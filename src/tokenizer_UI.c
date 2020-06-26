#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define INPUT_LIM 100

int main(){
  // add a way to loop the program eg check = 0
  char user_input[INPUT_LIM];
  printf("$ ");
  fgets(user_input,INPUT_LIM,stdin);
  char *str = user_input;

  char **token = tokenize(str);
  print_tokens(token);
  free_tokens(token);

  List *strings;
  strings = init_history();
  add_history(strings,str);
  print_history(strings);
}
