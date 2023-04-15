#ifndef HW1Header
#define HW1Header

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node   //define the node struct
{
	int key;
	struct Node* left, * right;
}node;

typedef struct Binary_tree // define the Binary_tree struct
{
	node* root;
	int num_nodes;
}bin_tree;

node* create_node(int key); // crete new node of the binary tree left and right pointers are NULL
void insert_tree(bin_tree* tree, node** root, int key, int* flag); // recursive function get pointer to binary_tree struct and pointer to pointer to root and the key value. add key value to tree, if key exist print a message.
void empty_tree(node** root); // get pointer to pointer to root of the tree free all allocated memory in tree
int bin_search(node* root, int key); // recursive function get pointer to root and key value return 1 if key exsit in the tree else return 0
void printInOrder(node* root); // recursive function get pointer to root and print all keys in-order.
int tree_h(node* root); // recursive function get pointer to root and calculate the height of the tree.
void find_max(node* root); // this function get pointer to root and find and print the maximum key in the tree.
void min_k_print(node* root, int k, int* cnt); // recursive function get pointer to root int k and pointer to counter assined to zero print the lowest values in from large to low.
#endif 