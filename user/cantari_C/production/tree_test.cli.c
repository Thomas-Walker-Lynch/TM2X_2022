
#pragma push_macro("IFACE_ONLY")
#define IFACE_ONLY
  #include "stdint.h"
  #include "stdbool.h"
  #include "stdio.h"
  #include "stdlib.h"
  #include "tree.lib.c" 
#pragma pop_macro("IFACE_ONLY")

int main(){
  Tree *tree = (Tree *) malloc(sizeof(Tree));
  tree->connect(tree);

  Tree_State *tree_state = (Tree_State *) malloc(sizeof(Tree_State));
  tree->make(tree_state ,3 ,7);

  tree->print(tree_state ,stdout);
  fprintf(stdout ,"\n");
}
