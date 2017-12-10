#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node * left;
	struct Node * right;	
};

struct Node * create_node (int data) {
	struct Node * _node;
	struct Node node;
	node.data = data;
	node.left = NULL;
	node.right = NULL;
	_node = &node;
	return _node;
} 

void insert_node(struct Node *root,int data) {
	struct Node *node = create_node(data);
	struct Node *current = root;
	printf("%s\n", root->right == NULL ? "true":"false");
	printf("%d\n", current->data);
	printf("%s\n", current->right == NULL ? "true":"false");
	exit(1);

//	while (1) {
//		if (current->data >= data) {
//			if (current->left == NULL) {
//				current->left = node;
//				break;
//			}
//			current = current->left;
//		} else {
//			printf("%s\n", current->right == NULL ? "true":"false");
//			exit(1);
//			if (current->right == NULL) {
//				current->right = node;
//				break;
//			}
//			current = current->right;
//		}	
//	}
}

struct Node * create_tree(int *arr, int size) {
	struct Node * root;
	root = create_node(arr[0]);
	for (int i = 1; i < size; i++) {
		insert_node(root, arr[i]);
	}

	return root;
}

void pre_order(struct Node * root) {
	printf("%d,", root->data);
	if (root->left != NULL) {
		pre_order(root->left);
	}

	if (root->right != NULL) {
		pre_order(root->right);
	}
}

int main () {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	struct Node *root = create_tree(arr, 10);
	pre_order(root);
}
