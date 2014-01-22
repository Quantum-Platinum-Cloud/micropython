#include <stdint.h>

// options to control how Micro Python is built

#define MICROPY_EMIT_THUMB          (1)
#define MICROPY_EMIT_INLINE_THUMB   (1)
#define MICROPY_ENABLE_GC           (1)
#define MICROPY_ENABLE_REPL_HELPERS (1)
#define MICROPY_ENABLE_FLOAT        (1)

// type definitions for the specific machine

#define BYTES_PER_WORD (4)

typedef int32_t machine_int_t; // must be pointer size
typedef uint32_t machine_uint_t; // must be pointer size
typedef void *machine_ptr_t; // must be of pointer size
typedef const void *machine_const_ptr_t; // must be of pointer size
typedef float machine_float_t;

machine_float_t machine_sqrt(machine_float_t x);

// board specific definitions

// choose 1 of these boards
//#define PYBOARD
#define PYBOARD4
//#define STM32F4DISC

#if defined(PYBOARD) || defined(PYBOARD4)
#define BOARD_HAS_MMA7660   (1)
#define BOARD_HAS_LIS3DSH   (0)
#else
#define BOARD_HAS_MMA7660   (0)
#define BOARD_HAS_LIS3DSH   (1)
#endif

#define STM32F40_41xxx
#define USE_STDPERIPH_DRIVER
#define HSE_VALUE (8000000)
