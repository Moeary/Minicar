/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef HIVIEW_BASE_PLUGIN_PLATFORM_H
#define HIVIEW_BASE_PLUGIN_PLATFORM_H
#include <memory>
#include <mutex>
#include <string>

#include "defines.h"
#include "dynamic_module.h"
#include "event_dispatch_queue.h"
#include "event_loop.h"
#include "event_source.h"
#include "pipeline.h"
#include "plugin.h"
#include "plugin_config.h"
#include "plugin_extra_info.h"

#include "singleton.h"
namespace OHOS {
namespace HiviewDFX {
class HiviewPlatform : public HiviewContext, public Singleton<HiviewPlatform> {
public:
    HiviewPlatform();
    ~HiviewPlatform();
    bool InitEnvironment(const std::string& defaultDir = "", const std::string& cloudUpdateDir = "",
                         const std::string& workDir = "", const std::string& persistDir = "");
    void ProcessArgsRequest(int argc, char* argv[]);
    void StartLoop();

    void PostOrderedEvent(std::shared_ptr<Plugin> plugin, std::shared_ptr<Event> event) override;
    void PostUnorderedEvent(std::shared_ptr<Plugin> plugin, std::shared_ptr<Event> event) override;
    void RegisterOrderedEventListener(std::weak_ptr<EventListener> listener) override;
    void RegisterUnorderedEventListener(std::weak_ptr<EventListener> listener) override;
    bool PostSyncEventToTarget(std::shared_ptr<Plugin> caller, const std::string& calleeName,
                               std::shared_ptr<Event> event) override;
    void PostAsyncEventToTarget(std::shared_ptr<Plugin> caller, const std::string& calleeName,
                                std::shared_ptr<Event> event) override;
    void RequestUnloadPlugin(std::shared_ptr<Plugin> caller) override;
    std::list<std::weak_ptr<Plugin>> GetPipelineSequenceByName(const std::string& name) override;
    std::shared_ptr<EventLoop> GetSharedWorkLoop() override;
    std::string GetHiViewDirectory(DirectoryType type) override;
    std::string GetHiviewProperty(const std::string& key, const std::string& defaultValue) override;
    bool SetHiviewProperty(const std::string& key, const std::string& value, bool forceUpdate) override;
    void PublishPluginCapacity(PluginCapacityInfo &pluginCapacityInfo) override;
    void GetRemoteByCapacity(const std::string& plugin, const std::string& capacity,
        std::list<std::string> &deviceIdList) override;
    int32_t PostEventToRemote(std::shared_ptr<Plugin> caller, const std::string& deviceId,
        const std::string& targetPlugin, std::shared_ptr<Event> event) override;

    bool IsReady() override
    {
        return isReady_;
    }

    std::shared_ptr<Plugin> GetPluginByName(const std::string& name);
    const std::map<std::string, std::shared_ptr<Plugin>>& GetPluginMap()
    {
        return pluginMap_;
    }

    const std::map<std::string, std::shared_ptr<Pipeline>>& GetPipelineMap()
    {
        return pipelines_;
    }

    const std::map<std::string, std::shared_ptr<EventLoop>>& GetWorkLoopMap()
    {
        return privateWorkLoopMap_;
    }

    void SetPluginConfigName(const std::string& configName)
    {
        defaultConfigName_ = configName;
    }

private:
    void StartPlatformDispatchQueue();
    void CreatePlugin(const PluginConfig::PluginInfo& pluginInfo);
    void CreatePipeline(const PluginConfig::PipelineInfo& pipelineInfo);
    void InitPlugin(const PluginConfig& config __UNUSED, const PluginConfig::PluginInfo& pluginInfo);
    void NotifyPluginReady();
    void ScheduleCreateAndInitPlugin(const PluginConfig::PluginInfo& pluginInfo);
    DynamicModule LoadDynamicPluginIfNeed(const PluginConfig::PluginInfo& pluginInfo) const;
    std::string GetDynamicLibName(const std::string& name, bool hasOhosSuffix) const;
    std::shared_ptr<EventLoop> GetAvaliableWorkLoop(const std::string& name);
    void CleanupUnusedResources();
    void UnloadPlugin(const std::string& name);
    void StartEventSource(std::shared_ptr<EventSource> source);
    void ValidateAndCreateDirectories(const std::string& localPath, const std::string& cloudUpdatePath,
                                  const std::string& workPath, const std::string& persistPath);
    void LoadBusinessPlugin(const PluginConfig& config);
    void ExitHiviewIfNeed();
    std::string GetPluginConfigPath();
    void UpdateBetaConfigIfNeed();
    bool isReady_;
    std::string defaultConfigDir_;
    std::string cloudUpdateConfigDir_;
    std::string defaultWorkDir_;
    std::string defaultPersistDir_;
    std::string defaultConfigName_;
    std::unique_ptr<EventDispatchQueue> orderQueue_;
    std::unique_ptr<EventDispatchQueue> unorderQueue_;
    std::shared_ptr<EventLoop> sharedWorkLoop_;
    std::map<std::string, std::shared_ptr<Plugin>> pluginMap_;
    std::map<std::string, std::shared_ptr<Pipeline>> pipelines_;
    std::map<std::string, std::shared_ptr<EventLoop>> privateWorkLoopMap_;
    std::map<std::string, std::string> hiviewProperty_;
};
} // namespace HiviewDFX
} // namespace OHOS
#endif // HIVIEW_BASE_PLUGIN_PLATFORM_H
