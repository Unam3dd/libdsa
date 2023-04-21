#ifndef BUFFER_H
#define BUFFER_H

#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

#include <string.h>
#include <stdint.h>

#define BUFFER_CREATE(T,NAME,SIZE)			\
	struct buffer##NAME {					\
		T	data[SIZE];						\
											\
		union {								\
			uint64_t	*ui64;				\
			uint32_t	*ui32;				\
			uint16_t	*ui16;				\
			uint8_t		*ui8;				\
			int64_t		*i64;				\
			int32_t		*i32;				\
			int16_t		*i16;				\
			int8_t		*i8;				\
			long		*ilong;				\
			int			*iint;				\
			short		*ishort;			\
			char		*ichar;				\
		};									\
											\
		union {								\
			size_t		len;				\
			size_t		size;				\
		};									\
		size_t			capacity; 			\
	} NAME = { {0}, .capacity = SIZE }

#define BUFFER_INIT(T, buf) (buf.i##T = buf.data)
#define BUFFER_ZERO(buf) (memset(buf.data, 0, sizeof(buf.data)))
#define BUFFER_COPY(buf, src, N) (memcpy(buf.data, src, N))
#define BUFFER_MEM(buf, search, N) (memmem(buf.data, src, N))

#endif
