#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main(){
  char name[20];
  fgets(name,20,stdin);

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
  printf("%d\n",*start);
  printf("\n");

  printf("word end");
  char *end = word_terminator(str);
  printf("%c\n",*end);
  printf("\n");

  printf("count words");
  int a = count_words(str);
  printf("%d\n",a);
  printf("\n");

  printf("len");
  int b = len_word(str);
  printf("%d\n",b);
  printf("\n");

  printf("copy");
  char *copy = copy_str(str,b);
  while (*copy != '\0')
    printf("%c",*copy++);
  printf("\n");
}

int space_char(char c){
  if (c == '\n')
    return 1;
  
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
  
  if ((temp+i) == "\0"){
    temp = NULL;
    return temp;
  }
  
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
  int count = 0;
  int state = 0;

  while (*str){
    if (state == 0 && non_space_char(*str)){
      state = 1;
      ++count;
    }
    else if (state == 1 && space_char(*str))
      state = 0;
    *str++;
  }
  return count;
}

int len_word(char *str){
  char *start,*end;
  int len;

  start = word_start(str);
  end = word_terminator(str);

  len = end - start;

  return len;
}

char *copy_str(char *inStr, short len){
  char *copy = (char*) malloc(len+1);
  int i;

  for (i = 0; i < len; i++)
    copy[i] = inStr[i];

  copy[i] = '\0';

  return copy;
}

char **tokenize(char *str){
  
}
