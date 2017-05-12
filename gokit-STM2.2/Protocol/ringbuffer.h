/**
 * Project page: https://github.com/wangrn/ringbuffer
 * Copyright (c) 2013 Wang Ruining <https://github.com/wangrn>
 * @date 2013/01/16 13:33:20
 * @brief   a simple ringbuffer, DO NOT support dynamic expanded memory
 */

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <stdlib.h>

typedef struct{									//环形缓冲器
    size_t 	rb_capacity;				//容量
    char  	*rb_head;						//头
    char  	*rb_tail;						//尾
    char  	rb_buff[256];				//缓冲区
}RingBuffer;												
//struct RingBuffer;

// RingBuffer* rb_new(size_t capacity);
void 			rb_new(RingBuffer* rb);
void      rb_free(RingBuffer *rb);

size_t    rb_capacity(RingBuffer *rb);
size_t    rb_can_read(RingBuffer *rb);
size_t    rb_can_write(RingBuffer *rb);

size_t    rb_read(RingBuffer *rb, void *data, size_t count);
size_t    rb_write(RingBuffer *rb, const void *data, size_t count);

#endif
