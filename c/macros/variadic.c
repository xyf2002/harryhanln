#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int main(void){
  eprintf("Errors", "Another One");
}
