# Expression_Trees


Details:

An expression tree is a binary tree used for representing arithmetic expressions. Leaves are always operands (numbers, in this case), and non-leaf nodes are always operators (+, -, *, /). The child trees of any operator are the expressions that the operator is operating on.

We can also write arithmetic expressions in prefix or postfix notation. In prefix notation, operators go BEFORE what they are operating on. In postfix notation, operators go AFTER what they are operating on.

Once we have an expression tree, we can write it in either infix, postfix, or prefix notation by doing an inorder, postorder, or preorder traversal on the tree.

This C program asks for a postfix expression from the user along with their preference for conversion to prefix or infix. The program then builds an expression tree representing the expression and uses that tree to perform the desired conversion. The program also evaluates the original expression.

Included Files:

• types.h
• tree.h and tree.c
• stack.h and stack.c
• proj4.c

Structure:

• The included header files (types.h, tree.h, and stack.h) are provided. No changes should be made to them.

• functions in tree.c, stack.c, and proj4.c. Follow the comments on in each .c file.


Running your program:

*make*
This should produce the executable proj4.

Your program should then run with the statement: ./proj4

