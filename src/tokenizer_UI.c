#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  // add a way to loop the program eg check = 0
  char user_input[100];
  printf("$");
  fgets(user_input,100,stdin);
  char *str = user_input;

  char **token = tokenize(str);
  print_tokens(token);
  free_tokens(token);
}
