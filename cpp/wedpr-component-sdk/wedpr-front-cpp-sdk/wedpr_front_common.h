/**
 *  Copyright (C) 2023 WeDPR.
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
 * @file wedpr_front_common.h
 * @author: yujiechen
 * @date 2024-08-22
 */

#ifndef __WEDPR_FRONT_COMMON_H__
#define __WEDPR_FRONT_COMMON_H__

#include "wedpr_msg.h"

typedef void (*wedpr_msg_handler_cb)(struct wedpr_msg* response, void* context);

#endif
