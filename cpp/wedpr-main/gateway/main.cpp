/*
 *  Copyright (C) 2022 WeDPR.
 *  SPDX-License-Identifier: Apache-2.0
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 * @file main.cpp
 * @author: yujiechen
 * @date 2022-11-14
 */
#include "GatewayInitializer.h"
#include "wedpr-main/common/NodeStarter.h"

using namespace ppc::node;
int main(int argc, const char* argv[])
{
    std::string binaryName = "ppc-gateway-service";
    auto initializer = std::make_shared<ppc::gateway::GatewayInitializer>();
    auto ret = startProgram(argc, argv, binaryName, initializer);
    initializer.reset();
    std::cout << "[" << bcos::getCurrentDateTime() << "] ";
    std::cout << "The " << binaryName << " program exit normally." << std::endl;
    return ret;
}