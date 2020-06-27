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
  char *temp = str;

  char **token = tokenize(str);
  print_tokens(token);
  free_tokens(token);
  printf("\n");

  List *strings;
  strings = init_history();
  int num_words = count_words(str);

  for (int i = 0; i <num_words;i++){
    add_history(strings,temp);
    temp = word_terminator(temp);
    temp = word_start(temp);
  }
  
  search_history_UI(strings,str);
  free_history(strings);
}
