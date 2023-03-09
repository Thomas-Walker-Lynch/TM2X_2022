/*
Test the doubling array.

*/

#pragma push_macro("DECLARATION")
#define DECLARATIONS
#include "tape_2x.c"
#pragma pop_macro("DECLARATION")

test_0(){
  #pragma push_macro("DEFINITION")
  #define DEFINITIONS
  #include "tape_2x.c"
  #pragma pop_macro("DEFINITION")

}

int main(int argc, char **argv){

  test_0();

  return 0;
}
