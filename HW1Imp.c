#include "HW1Header.h"


void insert_tree(bin_tree* tree, node** root, int key, int* flag) // recursive function get pointer to binary_tree struct and pointer to pointer to root and the key value. add key value to tree, if key exist print a message.
{
	if (*root == NULL) // stop condition
	{
		node* temp;
		if ((temp = create_node(key)) == NULL) // allocate memory for new node and check if it failed
		{
			printf("create_node memory allocation failed.\n");
			empty_tree(&tree->root);
			exit(1);
		}
		*root = temp; // make current node to be the new node
		tree->num_nodes++; // update number of nodes in the tree
	}
	else
	{
		if (key < (*root)->key) // continue left if the key is smaller then current root
		{
			insert_tree(tree, &(*root)->left, key, flag);
		}
		else if (key > (*root)->key) // continue right if the key is larger then current root
			insert_tree(tree, &(*root)->right, key, flag);
		else { // this case is when the key equal to the node key value
			(*flag) = 0;
			printf("the key %d already in the tree.\n", key);
		}
	}
	return;
}

void printInOrder(node* root) // recursive function get pointer to root and print all keys in pre order.
{
	if (root == 0)
		return;
	printInOrder(root->left);
	printf("%d\n", root->key);
	printInOrder(root->right);
}

int tree_h(node* root) // recursive function get pointer to root and calculate the hight of the tree.
{
	int rh, lh;
	if (root == NULL) // stop condintion
		return -1;
	rh = tree_h(root->right); // recursive call for the right tree hight
	lh = tree_h(root->left); // recursive call for the left tree hight
	if (rh > lh) // take the larger hight and return +1 for the current level
		return rh + 1;
	else
		return lh + 1;

}

int bin_search(node* root, int key) // recursive function get pointer to root and key value return 1 if key exsit in the tree else return 0
{
	if (root == NULL) //stop condition didnt found the key
		return 0;
	if (root->key == key) // stop condition found the key
		return 1;
	if (root->key > key) // if the key is lower the current root->key we continue left
		return bin_search(root->left, key);
	else // if key larger then root->key value we continue right.
		return bin_search(root->right, key);
}

void find_max(node* root) // this function get pointer to root and find and print the maximum key in the tree
{
	while (!NULL)
	{
		if (root == NULL) // case of empty tree
		{
			printf("empty tree.\n");
			break;
		}
		else if (root->right != NULL) // advance left in the tree where all values are higher then root->key
			root = root->right;
		else // if there is no where to go left we and up in the highest key value.
		{
			printf("the Maximum key is: %d\n", root->key);
			break;
		}
	}
}

void min_k_print(node* root, int k, int* cnt) // recursive function get pointer to root int k and pointer to counter assined to zero print the lowest values in from large to low.
{
	if (root == NULL || *cnt >= k) // stop condition when we had k prints or we made it to the last right node which the lrager in the tree
		return;
	min_k_print(root->left, k, cnt); // recursive call to continue to the last left node which the lowest are.
	if (*cnt < k) // if we didnt print k values enter the condition
	{
		printf("%d ", root->key); // print the low value of the sub tree
		(*cnt)++; // advance k
	}
	min_k_print(root->right, k, cnt); // same progress for the right sub tree
}

void empty_tree(node** root) // free all allocated memory in tree
{
	if ((*root) == NULL) // stop condition
		return;
	empty_tree(&((*root)->left)); // recursive call for the left root sub tree
	empty_tree(&((*root)->right)); // recursive call for the right root sub tree
	free(*root); // free current node;
	*root = NULL;
}

node* create_node(int key) // crete new node of the binary tree left and right pointers are NULL
{
	node* new_node;
	if ((new_node = (node*)malloc(sizeof(node))) == NULL) // allocate memory and check if it failed
		return NULL;
	new_node->key = key; // update key
	new_node->left = NULL; // assign NULL for the right and left nodes.
	new_node->right = NULL;
	return new_node; // return the node
}