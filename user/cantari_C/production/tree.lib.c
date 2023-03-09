#ifndef TREE
#define TREE

#pragma push_macro("IFACE_ONLY")
#define IFACE_ONLY
  #include <stdint.h>  
  #include <stdio.h>  
#pragma pop_macro("IFACE_ONLY")

typedef struct {
  uint32_t element_extent;
  uint8_t arity;
} Tree_State;

// arity is a bit count, element_extent is a max byte index
struct Tree_Struct{
  void (*connect)(struct Tree_Struct *t);
  void (*make)(Tree_State *ts ,uint8_t arity ,uint32_t element_extent); 
  void (*print)(Tree_State *ts ,FILE *);
  uint32_t (*element_extent)(Tree_State *ts);
  /*
  void *(*demote)(uint64_t index);
  void (*delete)(uint64_t index);
  void (*read)(uint64_t index ,void *dst);
  void (*write)uint64_t index ,void *src);
  */
};
typedef struct Tree_Struct Tree;

#if !defined(IFACE_ONLY)

  void make(Tree_State *ts ,uint8_t arity ,uint32_t element_extent){
    ts->arity = arity;
    ts->element_extent = element_extent;
  }

  void print(Tree_State *ts ,FILE *f){
    fprintf(f ,"(Tree_State %p %x %x)" ,ts ,ts->arity ,ts->element_extent);
  } 

  uint32_t element_extent(Tree_State *ts){
    return ts->element_extent;
  } 


  void connect(Tree *t){
    t->connect = connect;
    t->make = make;
    t->element_extent = element_extent;
  }

#endif


#endif
