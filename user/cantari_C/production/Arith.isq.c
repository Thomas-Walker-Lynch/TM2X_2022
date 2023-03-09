
#if defined(DECLARATIONS) && !defined(DECLARED_MISC)
#defined DECLARED_MISC
#include "misc.isq.c" 
#include "ISeq.isq.c"

// arithmetic inclusive bounds multiply, ⊡
// find t0 extent given t1_cell_in_t0_n and t1_n
INLINE_PREFIX mul_inclusive_32(Uint64 a ,Uint64 bb) return a * b + a + b;
INLINE_PREFIX mul_inclusive_64(Uint128 a ,Uint128 bb) return a * b + a + b;

// convert distance to cell in t1 to distance in t0, ◬
// given t1_cell with address a,  what is the t0_address for the first t0 cell in that t1 cell?
// t0_address - f_address_t0( 0 ) = t1_cell_in_t0_n ◬ a
INLINE_PREFIX mul_conv_32(Uint64 a ,Uint64 bb) return a * b + b;
INLINE_PREFIX mul_conv_64(Uint128 a ,Uint128 bb) return a * b + b;



#endif
