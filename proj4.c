/*
* Name: Jyad Aljohani
* Lab:  Tuesday 
* Assignment: Project 4 – Expression trees and traversals
*
* A program that prints out infix expression or prefix expression for user's input.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "tree.h"
#include "stack.h"

int main() {
   STACK* treeStack = init_stack();
    trav_fn MyOps[2] = {inorder, preorder};
    OP opr;
    char inputbuff[30];

  printf("Enter postfix expression :");
  fgets(inputbuff,30,stdin);
  inputbuff[strcspn(inputbuff, "\n")] = '\0';
  char * seg;
  seg = strtok(inputbuff, " ");
  int choice;


    while(seg != NULL)
    {
      int add = strcmp(seg,"+");
      int sub = strcmp(seg,"-");
      int time = strcmp(seg,"*");
      int div = strcmp(seg,"/");
      if(!(add ==0 || sub == 0 || time == 0 || div == 0)) {
        TREE * tree = create_singleton(atoi(seg));
        push(treeStack, tree);
      }
      else{
         TREE * first = pop(treeStack);
        TREE * second = pop(treeStack);

        switch(seg[0])
        {
        case '+':
          
          opr = 0; 
        
          break;
        case '-':
          
          opr = 1;

          break;
        case '*':
       
          opr =2;

          break;
        case '/':
       
          opr = 3;
          break;
        }
      TREE * treeopr =build_tree(opr, second , first); 
      push(treeStack, treeopr);
    }
      seg = strtok(NULL, " ");
  }
    printf("Enter 1 for infix, 2 for prefix:");
    scanf("%d", &choice);

    TREE * finaltree = pop(treeStack);
    char* buffer = malloc(30*sizeof(char));
    buffer[0] = '\0';
    (MyOps[choice-1])(finaltree, buffer);
    int resut = evaluate(finaltree);
      
      printf("\n%s\n", buffer);
      printf("\nAnswer: %d", resut);

      free(treeStack);
      free(finaltree);
    return 0;
}