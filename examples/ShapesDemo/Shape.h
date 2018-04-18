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
 * @file Shape.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _Shape_H_
#define _Shape_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <micrortps/client/xrce_client.h>

/*!
 * @brief This class represents the structure ShapeType defined by the user in the IDL file.
 * @ingroup SHAPE
 */
typedef struct ShapeType
{
    char* color;
    int32_t x;
    int32_t y;
    int32_t shapesize;

} ShapeType;

static bool serialize_ShapeType_topic(MicroBuffer* writer, const ShapeType* topic)
{
    serialize_sequence_char(writer, topic->color, strlen(topic->color) + 1);
    serialize_int32_t(writer, topic->x);
    serialize_int32_t(writer, topic->y);
    serialize_int32_t(writer, topic->shapesize);

    return writer->error == BUFFER_OK;
}

static bool deserialize_ShapeType_topic(MicroBuffer* reader, ShapeType* topic)
{
    uint32_t size_color = 0;
    deserialize_sequence_char(reader, &topic->color, &size_color);
    deserialize_int32_t(reader, &topic->x);
    deserialize_int32_t(reader, &topic->y);
    deserialize_int32_t(reader, &topic->shapesize);

    return reader->error == BUFFER_OK;
}

static uint32_t size_of_ShapeType_topic(const ShapeType* topic)
{
    uint32_t size = 0;

    size += 4 + get_alignment(size, 4) + strlen(topic->color) + 1;
    size += 4 + get_alignment(size, 4);
    size += 4 + get_alignment(size, 4);
    size += 4 + get_alignment(size, 4);

    return size;
}

static bool write_ShapeType(Session* session, ObjectId datawriter_id, StreamId stream_id, ShapeType* topic)
{
    if (session == NULL)
    {
        return false;
    }

    bool result = false;
    uint32_t topic_size = size_of_ShapeType_topic(topic);
    MicroBuffer* topic_buffer = NULL;

    if (128 < stream_id)
    {
        topic_buffer = prepare_best_effort_stream_for_topic(&session->output_best_effort_stream, datawriter_id, topic_size);
    }
    else
    {
        topic_buffer = prepare_reliable_stream_for_topic(&session->output_reliable_stream, datawriter_id, topic_size);
    }

    if (topic_buffer != NULL)
    {
        result = serialize_ShapeType_topic(topic_buffer, topic);
    }

    return result;
}

#endif // _Shape_H_