#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

List* init_history(){
  List *newList;
  newList = (List*) malloc (sizeof(List));
  newList->root = NULL;
  return newList;
}

void add_history(List *list, char *str){
  int len = len_word(str);
  int i,count;
  
  if (list->root == NULL){
    char *string_copy = copy_str(str,len);
    Item *newNode = (Item*) malloc (sizeof(Item));
    newNode->str = string_copy;
    newNode->id = 1;
    newNode->next = NULL;
    list->root = newNode;
  }
  else{
    Item *current;
    current = (list->root);
    while (current->next != NULL){
      current = current->next;
      ++count;
    }
    char *string_copy = copy_str(str,len);
    current->next = (Item*) malloc (sizeof(Item));
    current->next->id = (count+1);
    current->next->str = string_copy;
    current->next->next = NULL;
    
  }
}

char *get_history(List *list,int id){
  ;
}

void print_history(List *list){
  if (list->root == NULL)
    printf("No history");
  else{
    Item *current;
    current = (list->root);
    while (current != NULL){
      printf("History :\n ", current->str);
      current = current->next;
    }
  }
}

void free_history(List *list){
  ;
}
