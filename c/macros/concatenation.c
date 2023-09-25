// ## is concatenation macro
// # is stringizing macro
#define COMMAND(NAME) {#NAME, NAME ## _command}
struct command {
  char *name;
  void (*function) (void);
};

int main(void){
  struct command commands [2] = { COMMAND(load), COMMAND(quit), };
}
