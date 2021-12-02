/* File : bintree.h */
/* ADT binary tree */
/* Address is pointer */
/* ElType is integer */

#ifndef POHONBINER_H
#define POHONBINER_H

#include "boolean.h"

/* Selektor */
#define ROOT(p) (p)->info
#define LEFT(p) (p)->left
#define RIGHT(p) (p)->right

typedef int ElType;
typedef struct treeNode* Address;
typedef struct treeNode { 
     ElType info;
     Address left;
     Address right;
} TreeNode;

/* Definition of binary tree */
/* empty binary tree p = NULL */

typedef Address BinTree;

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree); 
/* Return a binary tree from root, left_tree, dan right_tree if the allocation succeed
   Return an empty tree (NULL) if the allocation failed */

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p);
/* I.S. Anything
   F.S. Created a tree stored in p
   Create a binary tree p from root, left_tree, dan right_tree, if the allocation succeed
   Create an empty tree (NULL) if the allocation failed */

Address newTreeNode(ElType val);
/* Make new node with val as its content and return the address for newly allocated node */

void deallocTreeNode (Address p);
/* I.S. p is defined
   F.S. p is deallocated*/

boolean isTreeEmpty (BinTree p);
/* Return true if p is an empty tree */

boolean isOneElmt (BinTree p);
/* Return trus if p in a tree with one element */

boolean isUnerLeft (BinTree p);
/* Return true if p only have left child  */

boolean isUnerRight (BinTree p);
/* Return true if p only have right child */

boolean isBinary (BinTree p);
/* Return true if p have both left and right child */

/* ****** Display Tree ***** */
void printPreorder(BinTree p);
/* I.S. p us defined */
/* F.S. All p's node already visited preorderly : root, left child, dan right child.
   Each tree started with ( and ended with ).
   Empty tree is marked with (). */
/* Example:
   (A()()) is a tree with one node and its value is A
   (A(B()())(C()())) is a tree with A as its root, (B()()) as its left child and (C()()) as its right child */

void printInorder(BinTree p);
/* I.S. p us defined */
/* F.S. All p's node already visited inorderly : root, left child, dan right child.
   Each tree started with ( and ended with ).
   Empty tree is marked with (). */
/* Example:
   (()A()) is a tree with one node and its value is A
   ((()B())A(()C())) is a tree with A as its root, (()B()) as its left child and (()C()) as its right child */

void printPostorder(BinTree p);
/* I.S. p us defined */
/* F.S. All p's node already visited postorderly : root, left child, dan right child.
   Each tree started with ( and ended with ).
   Empty tree is marked with (). */
/* Example:
   (()()A) is a tree with one node and its value is A
   ((()()B)(()()C)A) is a tree with A as its root, (()()B) as its left child and (()()C) as its right child */{

void printTree(BinTree p, int h);
/* I.S. p is defined, h is the indentation for the child */
/* F.S. All p's node is printed in the screen */
/* example, if h = 2:
1) preorder tree: (A()()) will be printed as:
A
2) preorder tree: (A(B()())(C()())) will be printed as:
A
  B
  C
3) preorder tree: (A(B(D()())())(C()(E()()))) will be printed as:
A
  B
    D
  C
    E
*/
#endif
