#ifndef INCLUSIVE_H
#define INCLUSIVE_H

/*--------------------------------------------------------------------------------
  Inclusive bound region addressing support.


*/
#include <stdint.h>
#include <limits.h>
#include "misc.h"

#define Uint64_n UINT64_MAX // maximum representable 64 bit integer
#define address_t_n UINT64_MAX  // maximum representable address value

  #define n_of(type) sizeof(type)-1

  // the n+1 could overflow:
  #define memcpyn(dst ,src ,n) memcpy(dst ,src ,n+1) 
  #define memcmpn(e0 ,e1 ,n) memcmp(e0 ,e1 ,n+1) 
  #define strncmpn(e0 ,e1 ,n) strncmp(e0 ,e1 ,n+1)
  #define str_octet_n(cstring) (strlen(cstring) - 1)

  typedef unsigned __int128 uint128_t;

  INLINE_PREFIX address_t power_2_extent(address_t n){
    if( n == 0 ) return 1;
    return (1 << (address_bit_length - __builtin_clz(n))) - 1;
  }

  INLINE_PREFIX address_t Mul_Inclusive(address_t n){


/*--------------------------------------------------------------------------------
  Many 3 operand address computations may use this.
*/
  typedef struct {
    address_t *a_0;
    address_t *a_1;
  } Inclusive·3opLL·Args;
  typedef struct {
    address_t *r;
  } Inclusive·3opLL·Ress;
  typedef struct {
    SQ·Lnk nominal;
    SQ·Lnk gt_address_t_n;
  } Inclusive·3opLL·Lnks;
  // retypes SQ·Lnk
  typedef struct{
    SQ·Ptr sequence;
    Inclusive·3opLL·Args *args;
    Inclusive·3opLL·Ress *ress;
    Inclusive·3opLL·Lnks *lnks;
  } Inclusive·3opLL·Lnk;


#endif
