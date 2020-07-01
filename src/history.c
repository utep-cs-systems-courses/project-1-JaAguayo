#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define SEARCH_LIM 10

List* init_history(){
  List *newList;
  newList = (List*) malloc (sizeof(List)); //space allocation for list
  newList->root = NULL; 
  return newList;
}

void add_history(List *list, char *str){
  int len = len_word(str);
  int count = 2;  //count set to 2 for id since I default root node added to have an id of 1
  
  if (list->root == NULL){  //if its the first node added
    char *string_copy = copy_str(str,len);  
    Item *newNode = (Item*) malloc (sizeof(Item));  //allocate space for node
    newNode->str = string_copy;  //adding setting each attribute to its correct values
    newNode->id = 1;
    newNode->next = NULL;
    list->root = newNode;  //make the root of List point to the first node added
  }
  else{
    Item *current;
    current = (list->root); //temp node made to iterate the list with the while loop
    while (current->next != NULL){
      current = current->next;
      ++count; //keeps track of what id each node is suppose to have
    }
    char *string_copy = copy_str(str,len);
    current->next = (Item*) malloc (sizeof(Item));
    current->next->id = count;
    current->next->str = string_copy;
    current->next->next = NULL;
  }
}

char *get_history(List *list,int id){
  char *history; //pointer that will be returned and point to the string user is looking for
  if (list->root == NULL)
    printf("List is empty there are no strings");
  else{
    Item *current;
    current = (list->root);
    while (current != NULL){
      if (current->id == id){
	history = current->str; //make the pointer point to the string that is stored in the node
	return history; 
      }
      current = current->next;
    }
  }
}

void print_history(List *list){
  if (list->root == NULL)
    printf("No history\n");
  else{
    Item *current;
    current = (list->root);
    while (current != NULL){
      printf("History %d: ", current->id); //prints the id and string of each node in the list
      printf("%s\n ", current->str);
      current = current->next;
    }
  }
}

void free_history(List *list){
  Item *current;
  Item *next;  //temp node to so I dont leave dangling pointers
  current = (list->root);

  while (current != NULL){
    next = current->next; //next set to the node after current so its not lost
    free(current->str);
    free(current); 
    current = next; //makes current set to node after current
  }
  free(list); //frees the list once all the nodes are free
}

int get_input(){
  int user_input = 0;
  int count = 0;

  while (user_input != 1 && user_input != 2 && user_input != 3){
    if (count > 0){
      printf("Please Enter 1-3\n");
      printf("\n");
    }
    printf("User Input History\n");
    printf("-------------------\n");
    printf("Enter number of the option you want to chose\n");
    printf("1. Search for an Input\n");
    printf("2. Print User History\n");
    printf("3. Quit Program\n");

    scanf("%d",&user_input);
    printf("\n");
    ++count;
  }
  
  return user_input;
}

char *search_history(List *list,char *str){
  char input[SEARCH_LIM];
  int is_exclamation = 0;
  int int_conv = 0;
  int i = 0;
  int num_words = count_words(str);
  char *found_str;

  while (is_exclamation == 0){
    printf("Enter the command '!(number of string you would like to find)'\n");
    fgets(input,SEARCH_LIM,stdin);
    printf("\n");

    if (input[0] == '!')
      is_exclamation = 1;
  }

  for (i = 1; input[i] >= '0'&& input[i] <= '9';i++)
    int_conv = 10 * int_conv + (input[i] - '0');

  if (int_conv > 0 && int_conv <= num_words)
    found_str = get_history(list,int_conv);
  else{
    printf("That string is not in history\n");
    printf("\n");
    found_str = NULL;
  }
  return found_str;
}

void history_UI(List *list,char *str){
  char *search_node;
  int user_input = 0;
  int search = 0;
  int print = 0;
  int quit = 0;

  user_input = get_input();
  printf("\n");

  if (user_input == 3)
    quit = 1;
  
  while (quit == 0){
    if (user_input == 1){
      search_node = search_history(list,str);
      if (search_node == NULL)
	;
      else{
	printf("The string found in history\n");
	printf("--->");
	printf("%s",search_node);
	printf("<---\n");
	printf("\n");
      }
    }
    else{
      print_history(list);
      printf("\n");
    }
    
    user_input = get_input();
    printf("\n");

    if (user_input == 3)
      quit = 1;
  }
}
