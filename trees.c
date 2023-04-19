/*Implementation of a binary tree in C*/

/*Tree Definitions:
Siblings -> Same parent
Leaf -> A node without children
Internal Node -> A node that inst a Leaf
Edge -> Connects two nodes (parent and child)
Path -> A collection of edges that join two nodes (not exactly a parent and child)
Height -> The longest path from the node to a leaf
Depth-> The path from the node to the root
Height of a tree -> The height of the root
Subtree -> A subtree is a tree that is made from the tree T, but considering n (a node in T) as the root
*/

/*Binary Tree Definition:
1. A empty tree;
2. A node (root) of a binary tree with two subtrees*/

/*Binary Tree Traversals:
Inorder: Left -> Root -> Right
Preorder: Root -> Left -> Right
Postorder: Left -> Right -> Root*/

#include <stdio.h>
#include <stdlib.h>

/*Binary Tree ADT*/
/*Consists of a integer data and two binary trees as children*/
typedef struct binary_tree {
    int item;
    binary_tree *left;
    binary_tree *right;
} binary_tree;



binary_tree* create_empty_binary_tree();
binary_tree* create_binary_tree(int item, binary_tree *left, binary_tree *right);
binary_tree* search(binary_tree *bt, int item);
int is_empty(binary_tree *bt);
void print_in_order(binary_tree *bt);
void print_pre_order(binary_tree *bt);
void print_post_order(binary_tree *bt);

int main(void)
{

}

/*Creates a empty binary tree ADT*/
binary_tree* create_empty_binary_tree()
{   
    return NULL;
}

/*Creates a binary tree with data ITEM and two children LEFT and RIGHT*/
binary_tree* create_binary_tree(int item, binary_tree *left, binary_tree *right)
{
    binary_tree *new_binary_tree = (binary_tree*)malloc(sizeof(binary_tree));

    new_binary_tree->item = item;
    new_binary_tree->left = left;
    new_binary_tree->right = right;

    return new_binary_tree;
}

int is_empty(binary_tree *bt)
{
    if(bt == NULL)
    {
        return 1;
    }

    return 0;
}

/*Print Inorder Traversal a binary tree BT*/
void print_in_order(binary_tree *bt)
{
    if(!is_empty(bt))
    {
        print_in_order(bt->left);
        printf("%d", bt->item);
        print_in_order(bt->right);
    }
}

/*Print Preorder Traversal a binary tree BT*/
/*Root -> Left -> Right*/
void print_pre_order(binary_tree *bt)
{
    if(!is_empty(bt))
    {
        printf("%d", bt->item);
        print_in_order(bt->left);
        print_in_order(bt->right);
    }
}

/*Print Postorder Traversal a binary tree BT*/
/*Left -> Right -> Root*/
void print_post_order(binary_tree *bt)
{
    if(!is_empty(bt))
    {
        print_in_order(bt->left);
        print_in_order(bt->right);
        printf("%d", bt->item);
    }
}
