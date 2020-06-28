#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

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
    free(current); 
    current = next; //makes current set to node after current
  }
  free(list); //frees the list once all the nodes are free
}

void search_history_UI(List *list, char *str){
  char *search_node;
  int num_node = 0;
  int search = 1;
  int print = 0;;

  int num_words = count_words(str);

  while(search == 1){    
    printf("\n");
    printf("Do you want to search for a string?\n");
    printf("\n");
    printf("yes = 1\n");
    printf("no = 0\n");
    
    printf("$");
    scanf("%d",&search); //user input to check if user wants to look for a string
    printf("\n");

    while (search != 1 && search != 0){  //check to make sure input is a 0 or 1
      printf("Please enter either 1 for yes or 0 for no\n");
      printf("$");
      scanf("%d",&search);
      printf("\n");
    }
    
    if (search == 1){
      printf("Enter the number of the string you want to find\n");
      printf("!");
      scanf("%d",&num_node);
      if (num_node > 0 && num_node <= num_words){ //if the number entered is within the amount of
	search_node = get_history(list,num_node); //words even entered then it will find the string
	printf("string in history: ");
	printf("%s\n",search_node);
      }
      else
	printf("That string does not exist\n");
    }
  }
  printf("Would you like to print the history?\n");
  printf("1 for yes, 0 for no\n");
  printf("$");
  scanf("%d",&print); //allows user to print the history if they want

  while (print != 1 && print != 0){ //check if either 0 or 1 is inputed
    printf("Please enter either 1 for yes or 0 for no\n");
    printf("$");
    scanf("d",&print);
    printf("\n");
  }
  
  if (print == 1){
    printf("\n");
    print_history(list); //prints history
  }
}
