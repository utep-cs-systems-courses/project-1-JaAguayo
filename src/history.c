#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

List* init_history(){
  List newList-> root = (Item) malloc (sizeof(Item));
  return newList;
}
//after calling this once do a temp in main with and do word term and send it a new pointer
void add_history(List *list, char *str){
  int len = len_word(str);
  int i,count;
  
  if (*root == 0){
    char *string_copy = copy_str(str,len);
    Item newNode->str = string_copy;
    newNode->id = 1;
    list->root = newNode;
    list->root->newNode->next = NULL;
  }
  else{
    Item current = (list->root);
    while (current->next != NULL){
      currnt = current->next;
      ++count;
    }
    char *string_copy = copy_str(str,len);
    current->next = (Item) malloc (sizeof(Item));
    current->next->id = (count+1);
    current->next->str = string_copy;
    current->next->next = NULL;
    
  }
}

char *get_history(List *list){
  ;
}

void print_history(List *list){
  ;
}

void free_history(List *list){
  ;
}
