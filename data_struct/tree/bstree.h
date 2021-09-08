#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

typedef int Type;

typedef struct BSTreeNode {
	Type key;			// key value
	struct BSTreeNode *left;	// left child
	struct BSTreeNode *right;	// right child
	struct BSTreeNode *parent;	// parent node
}Node, *BSTree;

// pre-order search
void preorder_bstree(BSTree tree);

// in-order search
void inorder_bstree(BSTree tree);

//post-order search
void postorder_bstree(BSTree tree);

Node* bstree_search(BSTree x, Type key);

Node* iterative_bstree_search(BSTree x, Type key);

Node* bstree_minimum(BSTree tree);

Node* bstree_maximum(BSTree tree);

Node* bstree_successor(Node *x);

Node* bstree_predecessor(Node *x);

Node* insert_bstree(BSTree tree, Type key);

Node* delete_bstree(BSTree tree, Type key);

void destroy_bstree(BSTree tree);

void print_bstree(BSTree tree, Type key, int direction);

#endif
