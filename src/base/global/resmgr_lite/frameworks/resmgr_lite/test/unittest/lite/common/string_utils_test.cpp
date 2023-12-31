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

#include "string_utils_test.h"
#include <climits>
#include <gtest/gtest.h>
#include <thread>
#include "auto_mutex.h"
#include "test_common.h"
#include "utils/string_utils.h"

using namespace OHOS::Global::Resource;
using namespace testing::ext;
using namespace OHOS::I18N;

class StringUtilsTest : public testing::Test {
public:
    static void SetUpTestCase(void);

    static void TearDownTestCase(void);

    void SetUp();

    void TearDown();
};

void StringUtilsTest::SetUpTestCase(void)
{
    // step 1: input testsuit setup step
    g_logLevel = LOG_DEBUG;
}

void StringUtilsTest::TearDownTestCase(void)
{
    // step 2: input testsuit teardown step
}

void StringUtilsTest::SetUp()
{
    // step 3: input testcase setup step
}

void StringUtilsTest::TearDown()
{
    // step 4: input testcase teardown step
}

/*
 * @tc.name: StringUtilsFuncTest001
 * @tc.desc: Test FormatString, none file case.
 * @tc.type: FUNC
 */
HWTEST_F(StringUtilsTest, StringUtilsFuncTest001, TestSize.Level1)
{
    std::string result = FormatString("%d", 10001);
    EXPECT_EQ("10001", result);

    result = FormatString("I'm %s, I'm %d", "cici", 5);
    EXPECT_EQ("I'm cici, I'm 5", result);
}

void FuncMultiThread(int* num, Lock* lock)
{
    AutoMutex mtx(*lock);
    auto tmp = (*num);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    (*num) = tmp + 1;
}

void TestThread(int* num, int threadNum, Lock* lock)
{
    std::vector<std::thread> threads;
    for (int i = 0; i < threadNum; ++i) {
        threads.push_back(std::thread(FuncMultiThread, num, lock));
    }
    for (auto &thread : threads) {
        thread.join();
    }
}

/*
 * @tc.name: LockFuncTest001
 * @tc.desc: Test lock, none file case.
 * @tc.type: FUNC
 */
HWTEST_F(StringUtilsTest, LockFuncTest001, TestSize.Level1)
{
    int num = 0;
    int threadNum = 3;
    int result = num + threadNum;
    Lock lock;
    TestThread(&num, threadNum, &lock);
    EXPECT_EQ(result, num);
}
