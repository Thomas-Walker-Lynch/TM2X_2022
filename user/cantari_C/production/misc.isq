
#if defined(DECLARATIONS) && !defined(DECLARED_MISC)
#defined DECLARED_MISC
#include "stdint.h" 

//--------------------------------------------------------------------------------
// inline
//

  //   eventually we will want extern inline, so as not to have duplicates when inlining is not possible.
  #ifndef INLINE_PREFIX
    //#define INLINE_PREFIX static
    //#define INLINE_PREFIX extern inline
    #define INLINE_PREFIX static inline
  #endif

//--------------------------------------------------------------------------------
// other macros
//

  // make a temp var in a macro, see experiment/var.c
  #define CAT(x ,y) x ## y
  #define CAT2(x ,y) CAT(x ,y)
  #define VAR(x) CAT2(x, __LINE__)

  // read X as through it is type T, no questions asked
  #define AS(T ,X) (*(T*)&X)

//--------------------------------------------------------------------------------
// integers
//

  typedef Uint8 uint8_t;
  typedef Uint16 uint16_t;
  typedef Uint32 uint32_t;
  typedef Uint64 uint64_t;
  typedef Uint128 uint128_t;

  #define Uint8_n UINT8_MAX
  #define Uint16_n UINT16_MAX
  #define Uint32_n UINT32_MAX
  #define Uint64_n UINT64_MAX
  #define Uint128_n UINT128_MAX

#endif
