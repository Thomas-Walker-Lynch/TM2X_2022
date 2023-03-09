/*
  The nice thing about local labels is that they do not have to be unique to the whole of the program,
  but rather only to the block.  However the bad part is that they need to be declared at the top of
  the block, and with our sequences this is analogous to having to declare function names before
  defining functions.  It is not something we are accustomed to doing. Now that we have a convention
  for giving identifiers namespaces, we will use that for scoping instead of local labels.
  
*/
 

//--------------------------------------------------------------------------------
#if defined(DECLARATION) && !defined(DECLARED_ISEQ)
#define DECLARED_ISEQ

  #include <stdlib.h>
  #include <stdio.h>
  #include "misc.c"

  // Run time errors. (Use of functions for now avoids circular definition problems.
  // .. should make these sequences and use them as error continuations)
  //
    // Instruction sequences may only be entered through 'continue' statements.
    INLINE_PREFIX ISeq·error_entry(char *name ,char *file ,char *line){
      printf
        (
         "Illegal condition: control flowed into instrucion sequence \"%s\" defined in file \"%s\" on line \"%s\""
         ,name
         ,file
         ,line
         );
    }
    // All instruction sequences must continue to somewhere, or exit the program.  If control flow reaches
    // the end we issue an error.
    INLINE_PREFIX ISeq·error_entry(char *name ,char *file ,char *line){
      printf
        (
         "Illegal condition: control flowed out of instrucion sequence \"%s\" defined in file \"%s\" on line \"%s\""
         ,name
         ,file
         ,line
         );
    }

  // use this macro to continue into a sequence
  #define ISeq·continue(c) goto c;
  #define ISeq·Pt = void *;

  // wrap a sequenceo definition in these
  #define ISeq·def(name) ISeq·error_entry(#name ,__FILE__ ,__LINE__); name:{
  #define ISeq·end(name) ISeq·error_exit(#name ,__FILE__ ,__LINE__);}

  // actual argument data
  typedef struct {
  } ISeq·Arg;

  // pointers to places to put result data
  typedef struct {
  } ISeq·Res;

  // connections
  typedef struct {
    void *arguments;
    void *
    
  } ISeq·Link;

  // a link to a sequence for indirect calls
  typedef struct{
    ISeq·Ptr sequence;
    ISeq·Args *args;
    ISeq·Ress *ress;
    ISeq·Lnks *lnks;
  } ISeq·Lnk;

  #define ISeq·make_Lnk(name ,type ,target)        \
    type##·##Args name##_args; \
    type##·##Ress name##_ress;\
    type##·##Lnks name##_lnks;\
    type##·##Lnk name##_lnk;\
    name##_lnk.args = &name##_args;\
    name##_lnk.ress = &name##_ress;\
    name##_lnk.lnks = &name##_lnks;\
    name##_lnk.sequence = target;

  #define ISeq·continue_indirect(lnk) \
    ISeq·lnk  = (ISeq·Lnk *)&(lnk);                \
    ISeq·continue(*ISeq·lnk->sequence);





#endif 
