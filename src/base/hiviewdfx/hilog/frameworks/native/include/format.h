/*
 * Copyright (c) 2020 Huawei Device Co., Ltd.
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
#ifndef LOG_FORMAT_H
#define LOG_FORMAT_H
#include <iostream>
#include "hilog_common.h"
#include "hilogtool_msg.h"
namespace OHOS {
namespace HiviewDFX {
const char* ParsedFromLevel(uint16_t level);
int ColorFromLevel(uint16_t level);
void HilogShowBuffer(char* buffer, int bufLen, const HilogShowFormatBuffer& contentOut, HilogShowFormat showFormat);
} // namespace HiviewDFX
} // namespace OHOS
#endif /* LOG_FORMAT_H */
