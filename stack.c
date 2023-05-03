#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "tree.h"
#include "stack.h"
//YOU DO THIS
/*
 * init_stack creates and returns a new stack object.
 *
 * returns: the new stack object
 */
STACK* init_stack(void){ 
    
    STACK* stack = malloc(sizeof(STACK));
    stack->top = NULL;
    return stack;

}

/*
 * Push adds a value to the top of the given stack
 *
 * s: the stack to push onto
 * d: the data (a TREE) to push
 */
void push(STACK* s, TREE* d){
    NODE * sdata = malloc(sizeof(NODE));
    sdata->data = d;
    sdata->next = s->top;
    s->top = sdata;

}

/*
 * Pop removes and returns the top value (tree) on the given stack. It assumes the 
 * stack has at least one node.
 *
 * s: the stack to pop
 * returns: the TREE that was on the top of stack s
 */
TREE* pop(STACK* s){
    NODE * temp = s->top->next;
    TREE* val = s->top->data;
    free(s->top);
    s->top = temp;
    return val;
}

/*
 * free_stack frees all nodes on stack s
 *
 * s: the stack to free
 */
void free_stack(STACK* s){
    
    while(s->top->next != NULL){
        NODE * toptemp= s->top->next;
        free(toptemp);
        s->top = toptemp->next;
        toptemp= s->top;
    }
    free(s);
}