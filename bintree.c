#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree)
/* Return a binary tree from root, left_tree, dan right_tree if the allocation succeed
   Return an empty tree (NULL) if the allocation failed */
{
    BinTree nodeBaru = (BinTree) malloc(sizeof(BinTree));
    if (nodeBaru!=NULL){
        ROOT(nodeBaru) = root;
        LEFT(nodeBaru) = left_tree;
        RIGHT(nodeBaru) = right_tree;
    }
    return nodeBaru;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p)
/* I.S. Anything
   F.S. Created a tree stored in p
   Create a binary tree p from root, left_tree, dan right_tree, if the allocation succeed
   Create an empty tree (NULL) if the allocation failed */
{
    *p=NewTree(root,left_tree,right_tree);
}

Address newTreeNode(ElType val)
/* Make new node with val as its content and return the address for newly allocated node */
{
    Address baru = (Address) malloc(sizeof(TreeNode));
    if(baru!=NULL){
        ROOT(baru)=val;
        LEFT(baru)=NULL;
        RIGHT(baru)=NULL;
    }
    return baru;
}

void deallocTreeNode (Address p)
/* I.S. p is defined
   F.S. p is deallocated*/
{
    free(p);
}
boolean isTreeEmpty (BinTree p)
/* Return true if p is an empty tree */
{
    return p==NULL;
}
boolean isOneElmt (BinTree p)
/* Return trus if p in a tree with one element */
{
    if(isTreeEmpty(p)){
        return false;
    }else{
        return (RIGHT(p)==NULL) && (LEFT(p)==NULL);
    }
}
boolean isUnerLeft (BinTree p)
/* Return true if p only have left child  */
{
    if(!isTreeEmpty(p)){
        return (LEFT(p)!=NULL) && (RIGHT(p)==NULL);
    }else{
        return false;
    }
}
boolean isUnerRight (BinTree p)
/* Return true if p only have right child */
{
    if(!isTreeEmpty(p)){
        return (RIGHT(p)!=NULL) && (LEFT(p)==NULL);
    }else{
        return false;
    }
}
boolean isBinary (BinTree p)
/* Return true if p have both left and right child */
{
    if(!isTreeEmpty(p)){
        return (LEFT(p)!=NULL) && (RIGHT(p)!=NULL);
    }else{
        return false;
    }
}
/* ****** Display Tree ***** */
void printPreorder(BinTree p)
/* I.S. p us defined */
/* F.S. All p's node already visited preorderly : root, left child, dan right child.
   Each tree started with ( and ended with ).
   Empty tree is marked with (). */
/* Example:
   (A()()) is a tree with one node and its value is A
   (A(B()())(C()())) is a tree with A as its root, (B()()) as its left child and (C()()) as its right child */
{
    printf("(");
    if(!isTreeEmpty(p)){
        printf("%d",ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}
void printInorder(BinTree p)
/* I.S. p us defined */
/* F.S. All p's node already visited inorderly : root, left child, dan right child.
   Each tree started with ( and ended with ).
   Empty tree is marked with (). */
/* Example:
   (()A()) is a tree with one node and its value is A
   ((()B())A(()C())) is a tree with A as its root, (()B()) as its left child and (()C()) as its right child */
{
    printf("(");
    if(!isTreeEmpty(p)){
        printInorder(LEFT(p));
        printf("%d",ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}
void printPostorder(BinTree p)

/* I.S. p us defined */
/* F.S. All p's node already visited postorderly : root, left child, dan right child.
   Each tree started with ( and ended with ).
   Empty tree is marked with (). */
/* Example:
   (()()A) is a tree with one node and its value is A
   ((()()B)(()()C)A) is a tree with A as its root, (()()B) as its left child and (()()C) as its right child */{
    printf("(");
    if(!isTreeEmpty(p)){
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d",ROOT(p));
    }
    printf(")");
}

void spasiNKali(int n){
/*I.S. anything
F.S. spaces n times is printed on the screen*/
    int i;
    for(i=0;i<n;i++){
        printf(" ");
    }
}

void cetakTree(BinTree p, int h, int n){
    if(!isTreeEmpty(p)){
        spasiNKali(n*h);
        printf("%d\n",ROOT(p));
        cetakTree(LEFT(p),h,n+1);
        cetakTree(RIGHT(p),h,n+1);
    }
}

void printTree(BinTree p, int h)
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
{
    if(!isTreeEmpty(p)){
        cetakTree(p,h,0);
    }
}
