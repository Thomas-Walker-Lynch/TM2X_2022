/*

tqpe 0 is the system memory. We are pretty much limited to using memory
allocation over system memory to create tapes.  This code builds over tape 0, so
we will call it tape 1.

The tape defined in this file is based on an array.  It expands by allocating a
new array of twice the size, copying the data in the active area over, and
freeing the original array. We do not want to limit ourselves to this
implementation, so we will be careful not to expose the implementation details
on the public interface.

Movement of data to and from the tape is done through a tape head. The operation
of stepping the head then leads to concept of an address space. A tape head is a
separate structure. Perhaps we should assume a phantom head and provide address
space access directly as part of the tape.  In essence, system memory is done this.
The problem with doing this is that such accesses either do not trigger boundary
continuations, or the head would not be phantom, but rather just partially
implemented.  In addition, if a programmer wants entanglment accounting, all tape
reads and writes will have to be done through a head.

Later when we go to implement tape heads, the state for each head will contain
data descriving the head location on the tape. (In our model, a tape machine may
have multiple heads). A physical tape machine head does not have to hold
location because is just stays wherever it is left. (An interesting phenomena.)
A software analog would be for each head to keep a pointer into the
tape. However, after tape expansion, such pointers will become stale. A pointer
is a t0 address, we could instead keep a t1 address.  However, in doing so we
arrive at a contradiction.  In order to make use of the t1 address, the tape
interface must give us a method for doing so, but that means the tape
implementation itself must have an address space independent of the head that is
using an address to keep its location - the very problem we discussed in the
prior paragraph.

So it does not look practical to create a lone tape. We will include a
built in head which remains on cell 0, and can not be stepped.  We will
then add the instructions: sn0_cn1_t0_t1, and sn0_cn1_t0_t1, and sr


Hopefully in the future we will define a tape interface for system memory, and
define a memory allocator for tapes. Then we will have a single tape interface,
and thus be able to allocate child tapes on parent tapes seemlessly.


*/



#if defined(DECLARATION) && !defined(DECLARED_TAPE1)
#define DECLARED_TAPE1
#include "stdlib.h"
#include "stdint.h"

  /*-----------------------------------------------------------------------------------------
    Each tape instance has:
      1. state. Maintained by the methods only. The user must not directly change it

    Each method has
      1. method arguments type declaration.  

    All tapes share:
      1. an interface, contains a pointer to each method 
      2. method arguments container, contains a pointer per method, each
      pointing to the method's arguments

    Before a call to a method:
      1. User makes an instance of the appropriate method arguments type declaration
      2. initializes the arguments, some might be pointers
      3. puts a pointer to the arguments into the method arguments container

    Assume a result centric tableau (input arguments are pointers to the actual
    inputs, results written to the args struct)
  */
    typedef struct Tape1·State;

    typedef struct{
      Tape1·State *state;
      Uint32 *t1_cell_in_t0_n; // see document/address_mapping.txt for an explanation of this name
      Uint64 *tape_n;
      ISeq·Pt nominal;
      ISeq·Pt alloc_fail;
    } Tape1·Arg·Make;

    typedef struct{
      Tape1·State *state;
      Uint64 *t1_address;
      ISeq·Pt nominal;
      ISeq·Pt overflow;
    } Tape1·Arg·T1_Address_In_T0;

    typedef struct{
      Tape1·Arg·Make  *make_arg;
      Tape1·Arg·T1_Address_In_T0  *t1_address_in_t0_arg;

    } Tape1·Arg;

    typedef struct{
      ISeq·Pt make;
      ISeq·Pt t1_address_in_t0;

    } Tape1·IFace;

    typedef struct{
      ISeq·Pt make;

    } Tape1·IFace·Public;



#endif


#if defined(DEFINITION) && !defined(DEFINED_TAPE1)
#define DEFINED_TAPE1

  typedef struct{
    Uint32 t1_cell_in_t0_n;
    Uint64 tape_n;
    Uint64 active_n;
    Uint8 *tape;
  } Tape1·State;

Tape1·arg = malloc(sizeof(Tape1·Arg));

ISeq·def(Tape1·Make){
  Tape1·Make·Arg *arg = Tape1·arg.make_arg;
  Tape1·State *state = arg->state;

  Uint128 n = mul_inclusive_64( arg->t1_cell_in_t0_n ,arg->tape_n );
  if( n >= Uint64_n ) continue( arg->alloc_fail );  
  Uint8 *tape_alloc = malloc( n+1 );
  if( !tape_alloc ) continue( arg->alloc_fail );

  continue(arg->nominal);

}ISeq·end(Tape1·Make)
  

#endif
