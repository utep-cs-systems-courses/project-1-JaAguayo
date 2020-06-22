#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main(){
  char name[20];
  fgets(name,10,stdin);

  printf("space char");
  int space_check = space_char(name[0]);
  printf("%d\n",space_check);
  printf("\n");

  printf("non space char");
  int non_check = non_space_char(name[0]);
  printf("%d\n",non_check);
  printf("\n");

  printf("word start");
  char *str = name;
  char *start = word_start(str);
  printf("%c\n",*start);
  printf("\n");

  printf("word end");
  char *end = word_terminator(str);
  printf("%c\n",*end);
  printf("\n");
}

int space_char(char c){
  if (c == '\n')
    return 0;
  
  else if ( c == ' '|| c == '\t')
    return 1;

  else
    return 0;
}

int non_space_char(char c){
  if (c == '\n')
    return 0;

  else if (c == ' ' || c == '\t')
    return 0;

  else
    return 1;
}

char *word_start(char *str){
  char *temp = str;
  int i;

  for (i = 0; space_char(temp[i]);i++)
    ;

  return temp + i;
}

char *word_terminator(char *word){
  char *temp = word;
  int i;

  temp = word_start(word);

  for (i = 0; non_space_char(temp[i]);i++)
    ;

  return temp + i;
}

int count_words(char *str){
  
}
