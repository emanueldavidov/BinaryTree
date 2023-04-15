#include "HW1Header.h"

int main()
{
	int operate = -1, cnt = 0, k;
	int key, flag = 0;
	bin_tree tree; // assign tree to be strcut type of Binary_tree
	tree.root = NULL;
	tree.num_nodes = 0;
	while (operate != 0) // operate hold the number of function the user choose.
	{
		printf("Press 0,1,2,3,4,5,6\n(0) exit the program.\n(1) insert node into tree.\n(2) print all the tree's keys in-order.\n(3) calculate and print the height of the tree.\n(4) find and print the Maximum key of the tree\n(5) search for value in tree and print the result.\n(6) print k lowest values in the tree from lowest to largest.\nOption:");
		scanf("%d", &operate);
		switch (operate)
		{
		case 0:
		{
			empty_tree(&tree.root);
			tree.num_nodes = 0;
			break;
		}
		case 1:
		{
			printf("please enter key value to insert: ");
			scanf("%d", &key); // gather information from user
			insert_tree(&tree, &tree.root, key, &flag); // call insert_tree function
			if (flag == 1)
				printf("the key %d successfully inserted to the tree.\n", key);
			flag = 1;
			break;
		}
		case 2:
		{
			printf("The tree is:\n");
			printInOrder(tree.root);
			printf("\n");
			break;
		}
		case 3:
		{
			printf("the height of tree is: %d\n", tree_h(tree.root));
			break;
		}
		case 4:
		{
			find_max(tree.root);
			break;
		}
		case 5:
		{
			printf("please enter value for search: ");
			scanf("%d", &key);
			if (bin_search(tree.root, key) == 1)
				printf("the value %d exist in the tree.\n", key);
			else
				printf("the value %d does not exist in the tree.\n", key);
			break;
		}
		case 6:
		{
			printf("please enter value k: ");
			scanf("%d", &k);
			if (tree.num_nodes < k) // check if k is not larger then the number of node in the tree
				printf("k is larger then the number of nodes in the tree.\n");
			else
			{
				min_k_print(tree.root, k, &cnt); // cnt is the counter for the recursive calls
				cnt = 0; // reset cnt for the next use.
				printf("\n");
			}
			break;
		}
		default:
			printf("invalid input.\n");
		}
	}
	return 0;
}