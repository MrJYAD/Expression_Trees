#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "tree.h"
#include "stack.h"
//
/*
 * create_singleton creates a new singleton (no children) tree
 * to hold an integer data value
 * 
 * d: the integer data
 * returns: a new TREE object holding d (with no children)
 */
TREE* create_singleton(int d){
    TREE* tree = malloc(sizeof(TREE));
    tree->data.leafnum = d;
    tree->isleaf = true;
    tree->left = NULL;
    tree->right = NULL;
    return tree; 


}

/*
 * build_tree creates a non-leaf tree with the given
 * operator and left/right subtrees
 * 
 * oper: the operator to be stored as the data for the new tree
 * l: the left subtree for the new tree
 * r: the right subtree for the new tree
 * returns: the newly created TREE object holding oper, l, and r
 */
TREE* build_tree(OP oper, TREE* l, TREE* r){
    TREE* tree = malloc(sizeof(TREE));
    tree->data.operator = oper;
    tree->left = l;
    tree->right = r;
    tree->isleaf = false;
    
    return tree;
}


/*
 * inorder does an inorder traversal on the given tree,
 * and writes the traversal in the given buffer. Here is the
 * inorder traversal algorithm:
 *      If the tree is a leaf, add its data to the buffer
 *      Otherwise:
 *          Recursively do an inorder traversal on the left subtree
 *          Add the current data to the buffer
 *          Recursively do an inorder traversal on the right subtree
 * 
 * You will also need to add ( ) around everything (left, data, right)
 * in the non-leaf case to express the correct order of operations.
 * 
 * 
 * tree: the expression tree to traverse
 * buffer: where the traversal will be written
 */
void inorder(TREE* tree, char* buffer){
     char anotherBuffer[10];
    if(tree->isleaf == true){
        sprintf(anotherBuffer, "%d", tree->data.leafnum);
        strcat(buffer, anotherBuffer);    
    }else{
        strcat(buffer, "(");    
        inorder(tree->left,buffer);
         
        if(tree->data.operator == PLUS )
        {
            strcat(buffer, "+");    
        }
        if(tree->data.operator == MINUS )
        {
            strcat(buffer, "-");    
        }
             if(tree->data.operator == TIMES )
        {
            strcat(buffer, "*");    
        }
             if(tree->data.operator == DIVIDE )
        {
            strcat(buffer, "/");    
        }
        inorder(tree->right,buffer);
        strcat(buffer, ")");    

    }
}

/*
 * preorder does an preorder traversal on the given tree,
 * and writes the traversal in the given buffer. Here is the
 * preorder traversal algorithm:
 *      If the tree is a leaf, add its data to the buffer
 *      Otherwise:
 *          Add the current data to the buffer
 *          Recursively do an preorder traversal on the left subtree
 *          Recursively do an preorder traversal on the right subtree
 * 
 * tree: the expression tree to traverse
 * buffer: where the traversal will be written
 */
void preorder(TREE* tree, char* buffer){
    char anotherBuffer[10];
  if(tree->isleaf == true){
        sprintf(buffer, "%d", tree->data.leafnum);
        strcat(buffer, anotherBuffer);    
        strcat(buffer, " ");    

    }else{
        if(tree->data.operator == PLUS )
        {
            strcat(buffer, "+");    
        }
        if(tree->data.operator == MINUS )
        {
            strcat(buffer, "-");    
        }
             if(tree->data.operator == TIMES )
        {
            strcat(buffer, "*");    
        }
             if(tree->data.operator == DIVIDE )
        {
            strcat(buffer, "/");    
        }
        strcat(buffer, " ");    
        inorder(tree->left,buffer);
        inorder(tree->right,buffer);
    }
}

/*
 * evaluate returns the evaluation of the expression
 * represented by the given expression tree.
 * 
 * If tree is a leaf, return its data
 * Otherwise, return the result of:
 *      (recursively evaluate left) op (recursively evaluate right)
 * 
 * Where "op" is the operator (+, -, *, /) stored in tree's data
 * 
 * tree: the expression tree to evalute
 * returns: the evaluation of tree
 */
int evaluate(TREE* tree){
    if(tree->isleaf == true){
        return tree->data.leafnum;
    }else{
        if(tree->data.operator == PLUS )
        {
            return  evaluate(tree->left) +  evaluate(tree->right);    
        }
        if(tree->data.operator == MINUS )
        {
            return  evaluate(tree->left) -  evaluate(tree->right);    
        }
        if(tree->data.operator == TIMES )
        {
            return  evaluate(tree->left) *  evaluate(tree->right);    
        }
            return  evaluate(tree->left) /  evaluate(tree->right);    
    }
}
/*
 * free_tree releases all the memory allocated
 * for the given tree.
 * 
 * tree: the expression tree to free
 */
void free_tree(TREE* t){
    if(t->left == NULL && t->right == NULL){
        free(t);
    }else{
    free_tree(t->left);
    free_tree(t->right);
    free(t);
    }
}