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
  //make into a function
  char *search_node;
  int num_node = 0;
  int search = 0;
  print_history(strings);
  printf("Do you want to search for a string? enter\n");
  printf("yes = 1\n");
  printf("no = 0\n");
  scanf("%d",&search);
  if (search == 1){
    printf("Enter the number of the string you want to find\n");
    printf("!");
    scanf("%d",&num_node);
    if (num_node > 1 && num_node < num_words){
       search_node = get_history(strings,num_node);
       printf("%s\n",search_node);
    }
    else
      printf("That string does not exist\n");
  }

  free_history(strings);
}
