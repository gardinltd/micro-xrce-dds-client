// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file BigHelloWorld.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _BigHelloWorld_H_
#define _BigHelloWorld_H_

#ifdef __cplusplus
extern "C"
{
#endif // ifdef __cplusplus

#include <stdint.h>
#include <stdbool.h>

#define BIG_HELLO_WORLD_STRING_SIZE 50000

/*!
 * @brief This struct represents the structure BigHelloWorld defined by the user in the IDL file.
 * @ingroup BIGHELLOWORLD
 */
typedef struct BigHelloWorld
{
    uint32_t index;
    char message[BIG_HELLO_WORLD_STRING_SIZE];

} BigHelloWorld;

struct ucdrBuffer;

bool BigHelloWorld_serialize_topic(
        struct ucdrBuffer* writer,
        const BigHelloWorld* topic);
bool BigHelloWorld_deserialize_topic(
        struct ucdrBuffer* reader,
        BigHelloWorld* topic);
uint32_t BigHelloWorld_size_of_topic(
        const BigHelloWorld* topic,
        uint32_t size);


#ifdef __cplusplus
}
#endif // ifdef __cplusplus

#endif // _BigHelloWorld_H_
