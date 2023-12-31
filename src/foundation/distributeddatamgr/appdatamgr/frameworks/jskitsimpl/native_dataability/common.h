/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef DA_JSKIT_NAPI_COMMON_PREDICATES_H
#define DA_JSKIT_NAPI_COMMON_PREDICATES_H

#include <string>
#include <vector>

#include "hilog/log.h"

namespace OHOS {
namespace DataAbilityJsKit {
static const OHOS::HiviewDFX::HiLogLabel PREFIX_LABEL = { LOG_CORE, 0xD001650, "DataAbilityJsKit" };

#define LOG_DEBUG(...) ((void)OHOS::HiviewDFX::HiLog::Debug(PREFIX_LABEL, __VA_ARGS__))
#define LOG_INFO(...) ((void)OHOS::HiviewDFX::HiLog::Info(PREFIX_LABEL, __VA_ARGS__))
#define LOG_WARN(...) ((void)OHOS::HiviewDFX::HiLog::Warn(PREFIX_LABEL, __VA_ARGS__))
#define LOG_ERROR(...) ((void)OHOS::HiviewDFX::HiLog::Error(PREFIX_LABEL, __VA_ARGS__))
#define LOG_FATAL(...) ((void)OHOS::HiviewDFX::HiLog::Fatal(PREFIX_LABEL, __VA_ARGS__))
} // namespace DataAbilityJsKit
} // namespace OHOS

#endif // DA_JSKIT_NAPI_COMMON_PREDICATES_H
