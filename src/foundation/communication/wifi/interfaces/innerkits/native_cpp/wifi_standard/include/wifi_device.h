/*
 * Copyright (C) 2021-2022 Huawei Device Co., Ltd.
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
#ifndef OHOS_WIFI_DEVICE_H
#define OHOS_WIFI_DEVICE_H

#include "i_wifi_device_callback.h"
#include "wifi_errcode.h"
#include "wifi_msg.h"

namespace OHOS {
namespace Wifi {
class WifiDevice {
public:
    static std::unique_ptr<WifiDevice> CreateWifiDevice(int system_ability_id);

    static std::unique_ptr<WifiDevice> GetInstance(int system_ability_id);

    virtual ~WifiDevice();

    /**
     * @Description Turn on Wi-Fi.
     *
     * @return ErrCode - operation result
     */
    virtual ErrCode EnableWifi() = 0;

    /**
     * @Description Turn off Wi-Fi.
     *
     * @return ErrCode - operation result
     */
    virtual ErrCode DisableWifi() = 0;

    /**
     * @Description Add a wifi device configuration.
     *
     * @param config - WifiDeviceConfig object
     * @param result - the device configuration's network id
     * @return ErrCode - operation result
     */
    virtual ErrCode AddDeviceConfig(const WifiDeviceConfig &config, int &result) = 0;

    /**
     * @Description Remove the wifi device config equals to input network id.
     *
     * @param networkId - want to remove device config's network id
     * @return ErrCode - operation result
     */
    virtual ErrCode RemoveDevice(int networkId) = 0;

    /**
     * @Description Remove all device configs.
     *
     * @return ErrCode - operation result
     */
    virtual ErrCode RemoveAllDevice() = 0;

    /**
     * @Description Get all the device configs.
     *
     * @param result - Get result vector of WifiDeviceConfig
     * @return ErrCode - operation result
     */
    virtual ErrCode GetDeviceConfigs(std::vector<WifiDeviceConfig> &result) = 0;

    /**
     * @Description Connecting to a Specified Network.
     *
     * @param networkId - network id
     * @return ErrCode - operation result
     */
    virtual ErrCode ConnectToNetwork(int networkId) = 0;

    /**
     * @Description Connect To a network base WifiDeviceConfig object.
     *
     * @param config - WifiDeviceConfig object
     * @return ErrCode - operation result
     */
    virtual ErrCode ConnectToDevice(const WifiDeviceConfig &config) = 0;

    /**
     * @Description Disconnect.
     *
     * @return ErrCode - operation result
     */
    virtual ErrCode Disconnect(void) = 0;

    /**
     * @Description Check whether Wi-Fi is active.
     *
     * @param bActive - active / inactive
     * @return ErrCode - operation result
     */
    virtual ErrCode IsWifiActive(bool &bActive) = 0;

    /**
     * @Description Get the Wi-Fi State.
     *
     * @param state - return current wifi state
     * @return ErrCode - operation result
     */
    virtual ErrCode GetWifiState(int &state) = 0;

    /**
     * @Description Obtains the current Wi-Fi connection information.
     *
     * @param info - WifiLinkedInfo object
     * @return ErrCode - operation result
     */
    virtual ErrCode GetLinkedInfo(WifiLinkedInfo &info) = 0;

    /**
     * @Description Set the country code.
     *
     * @param countryCode - country code
     * @return ErrCode - operation result
     */
    virtual ErrCode SetCountryCode(const std::string &countryCode) = 0;

    /**
     * @Description Obtains the country code.
     *
     * @param countryCode - output the country code
     * @return ErrCode - operation result
     */
    virtual ErrCode GetCountryCode(std::string &countryCode) = 0;

    /**
     * @Description Register callback function.
     *
     * @param callback - IWifiDeviceCallBack object
     * @return ErrCode - operation result
     */
#ifdef OHOS_ARCH_LITE
    virtual ErrCode RegisterCallBack(const std::shared_ptr<IWifiDeviceCallBack> &callback) = 0;
#else
    virtual ErrCode RegisterCallBack(const sptr<IWifiDeviceCallBack> &callback) = 0;
#endif

    /**
     * @Description Get the signal level object.
     *
     * @param rssi - rssi
     * @param band - band
     * @param level - return the level
     * @return ErrCode - operation result
     */
    virtual ErrCode GetSignalLevel(const int &rssi, const int &band, int &level) = 0;

    /**
     * @Description Get supported features
     *
     * @param features - return supported features
     * @return ErrCode - operation result
     */
    virtual ErrCode GetSupportedFeatures(long &features) = 0;

    /**
     * @Description Check if supported input feature
     *
     * @param feature - input feature
     * @return true - supported
     * @return false - unsupported
     */
    virtual bool IsFeatureSupported(long feature) = 0;

    /**
     * @Description  Get the device MAC address.
     *
     * @param result - Get device mac String
     * @return ErrCode - operation result
     */
    virtual ErrCode GetDeviceMacAddress(std::string &result) = 0;
};
}  // namespace Wifi
}  // namespace OHOS
#endif