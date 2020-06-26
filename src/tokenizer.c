#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

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
  char *copy = (char*) malloc((sizeof(char*))*(len+1));
  int i;

  for (i = 0; i < len; i++)
    copy[i] = inStr[i];

  copy[i] = '\0';

  return copy;
}

char **tokenize(char *str){
  int num_words = count_words(str);
  int i,len;
  char *temp = str;

  char **token = (char**) malloc((sizeof(char*))*(num_words+1));

  for (i = 0; i < num_words; i++){
    len = len_word(temp);
    token[i] = copy_str(temp,len);
    temp = word_terminator(temp);
    temp = word_start(temp);
  }
  token[i] = 0;

  return token;
}

void print_tokens(char **tokens){
  for (int i = 0; tokens[i] != 0;i++){
    printf("token %d: ",i);
    printf("%s",tokens[i]);
    printf("\n");
  }
}

void free_tokens(char **tokens){
  for (int i = 0; tokens[i] != 0;i++)
    free(tokens[i]);
  free(tokens);
}
