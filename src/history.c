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
  int count = 2;
  
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
    current->next->id = count;
    current->next->str = string_copy;
    current->next->next = NULL;
  }
}

char *get_history(List *list,int id){
  char *node;
  if (list->root == NULL)
    printf("List is empty there are no strings");
  else{
    Item *current;
    current = (list->root);
    while (current != NULL){
      if (current->id == id){
	node = current->str;
	return node;
      }
      current = current->next;
    }
  }
  return node;
}

void print_history(List *list){
  if (list->root == NULL)
    printf("No history\n");
  else{
    Item *current;
    current = (list->root);
    while (current != NULL){
      printf("History %d: ", current->id);
      printf("%s\n ", current->str);
      current = current->next;
    }
  }
}

void free_history(List *list){
  Item *current;
  Item *next;
  current = (list->root);

  while (current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  free(list);
}

int search_history_UI(List *list, char *str){
  char *search_node;
  int num_node = 0;
  int search = 0;

  int num_words = count_words(str);

  printf("Do you want to search for a string? enter\n");
  printf("yes = 1\n");
  printf("no = 0\n");

  scanf("%d",&search);
  if (search == 1){
    printf("Enter the number of the string you want to find\n");
    printf("!");
    scanf("%d",&num_node);
    if (num_node > 0 && num_node <= num_node){
      search_node = get_history(list,num_node);
      printf("%s\n",search_node);
    }
    else
      printf("That string does not exist\n");
  }
  
}
