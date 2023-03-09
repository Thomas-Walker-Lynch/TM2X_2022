// create a typedef and an object togther?  ah no..
typedef struct{
  int a;
  double b;
} pair_t a_pair;
//struct_declare.c:5:10: error: expected ‘=’, ‘,’, ‘;’, ‘asm’ or ‘__attribute__’ before ‘a_pair’

int main(){
  a_pair.a=7;
  a_pair.b=27.0;
  printf(" %d %f " ,a_pair.a ,a_pair.b);
}
