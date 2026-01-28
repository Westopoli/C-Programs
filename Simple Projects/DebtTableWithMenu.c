// Westley Yarlott
// This program uses a menu to allow the user to add, search, print, and clear a linked list of debts. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAME_LEN 30

struct debt{
	char company[NAME_LEN+1];
	double balance;
	double minimum;
	double interest_rate;
	struct debt *next;
};

struct debt *add_to_list(struct debt *list);
void search_list(struct debt *list);
void print_list(struct debt *list);
void clear_list(struct debt *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct debt *debt_list = NULL;  
  printf("Operation Code: a for adding to the list, s for searching"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': debt_list = add_to_list(debt_list);
                break;
      case 's': search_list(debt_list);
                break;
      case 'p': print_list(debt_list);
                break;
      case 'q': clear_list(debt_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}
/**********************************************************
 * add_to_list: Adds a new node to the end of the list.   *
 *              Returns a pointer to the head of the list. *
 **********************************************************/
struct debt *add_to_list(struct debt *list)
{
  // Two pointers are needed to add a new node to the end of the list
  struct debt *new_node;
  struct debt *current;
  
  // Allocates memory for the new node and check for success
  new_node = malloc(sizeof(struct debt));
  if (new_node == NULL) {
    printf("malloc failed in add_to_list\n");
    return list;
  }

  // Prompt the user for input and store it in the new node
  printf("Enter company name: ");
  read_line(new_node->company, NAME_LEN);
  printf("Enter balance: ");
  scanf("%lf", &new_node->balance);
  printf("Enter monthly minimum: ");
  scanf("%lf", &new_node->minimum);
  printf("Enter interest rate: ");
  scanf("%lf", &new_node->interest_rate);
  
  // If the list is empty, the new node becomes the head of the list
  if (list == NULL) {
    return new_node;
  }

  // Traverses the list to find the last node
  current = list;
  while (current->next != NULL) {
    current = current->next;
  }

  // Appends the new node to the end of the list
  current->next = new_node;
  return list;
}

/**********************************************************
 * search_list: Searches the list for a node with a       *
 *              specified company name.                   *
 **********************************************************/
void search_list(struct debt *list)
{
  // A flag variable is needed to indicate if the company was found
  int flag = 0; 
  char company[NAME_LEN+1];

  // Prompts the user for the company name to search for
  printf("Enter company name: ");
  read_line(company, NAME_LEN);
  
  // Uses a for loop to traverse the list and search for the company
  struct debt *p;
  for (p = list; p != NULL; p = p->next)
    // Compares the company name in the current node with the input
    if (strcmp(p->company, company) == 0)
    {
      flag = 1;
      printf("%-28s%12.2f%12.2f%12.2f\n", 
        p->company, 
        p->balance, 
        p->minimum, 
        p->interest_rate);
    }
  if (flag == 0)
    printf("not found\n");
}

/**********************************************************
 * print_list: Prints the contents of the list.           *
 **********************************************************/
void print_list(struct debt *list)
{
  printf("company                          balance     minimum    interest\n");
  while(list != NULL){
    printf("%-28s%12.2f%12.2f%12.2f\n", 
      list->company, 
      list->balance, 
      list->minimum, 
      list->interest_rate);
    list = list->next;
  }
}

/**********************************************************
 * clear_list: Frees the memory allocated for the list.    *
 **********************************************************/
void clear_list(struct debt *list)
{
  struct debt *p;
  while(list != NULL)
  {
    p = list;
    list = list->next;
    free(p);
  }

}

/**********************************************************
 * read_line: Reads a line of text from the standard input. *
 **********************************************************/
int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}
