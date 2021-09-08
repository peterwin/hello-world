/**
 * binary search tree:
 *
 * @author
 * @date
 */

#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

static Node* create_bstree_node(Type key, Node *parent, Node *left, Node * right)
{
	Node *p;

	if ((p = (Node *)malloc(sizeof(Node))) == NULL ) {
		printf("malloc failed\n");
		return NULL;
	}

	p->key = key;
	p->left = left;
	p->right = right;
	p->parent = parent;

	return p;
}

void preorder_bstree(BSTree tree)
{
	if (tree != NULL) {
		printf("%d ", tree->key);
		preorder_bstree(tree->left);
		preorder_bstree(tree->right);
	}
}

void inorder_bstree(BSTree tree)
{
	if (tree != NULL) {
		inorder_bstree(tree->left);
		printf("%d ", tree->key);
		inorder_bstree(tree->right);
	}
}

void postorder_bstree(BSTree tree)
{
	if (tree != NULL) {
		postorder_bstree(tree->left);
		postorder_bstree(tree->right);
		printf("%d ", tree->key);
	}
}

/*
 * search the node value = key
 */
Node *bstree_search(BSTree x, Type key)
{
	if (x == NULL || x->key == key) 
		return x;

	if (key >= x->key) {
		return bstree_search(x->right, key);
	} else {
		return bstree_search(x->left, key);
	}
}

Node* iterative_bstree_search(BSTree x, Type key)
{
	while ((x != NULL) && (x->key != key)) {
		if (key >= x->key) {
			x = x->right;
		} else {
			x = x->left;
		}
	}

	return x;
}

Node* bstree_maximum(BSTree tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->right != NULL) {
		tree = tree->right;
	}

	return tree;
}

Node* bstree_minimum(BSTree tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->left != NULL) {
		tree = tree->left;
	}

	return tree;
}

//
Node* bstree_predecessor(Node *x)
{
	if (x->left != NULL) {
		return bstree_maximum(x->left);
	}

	// ??
	Node* y = x->parent;
	while ((y != NULL) && (x == y->left)) {
		x = y;
		y = y->parent;
	}

	return y;
}

Node* bstree_successor(Node *x)
{
	if (x->right != NULL) {
		return bstree_minimum(x->right);
	}

	// ??
	Node* y = x->parent;
	while ((y != NULL) && (x == y->right)) {
		x = y;
		y = y->parent;
	}

	return y;
}

static Node* bstree_insert(BSTree tree, Node *z)
{
	Node *y = NULL;
	Node *x = tree;

	while (x != NULL) {
		y = x;
		if (z->key < x->key) {
			x = x->left;
		} else {
			x = x->right;
		}
	}

	z->parent = y;
	if (y == NULL) {
		tree = z;
	} else if (z->key < y->key) {
		y->left = z;
	} else {
		y->right = z;
	}

	return tree;
}

Node* insert_bstree(BSTree tree, Type key)
{
	Node *z;

	if ((z = create_bstree_node(key, NULL, NULL, NULL)) == NULL) {
		printf("create tree failed\n");
		return tree;
	}

	return bstree_insert(tree, z);
}

static Node* bstree_delete(BSTree tree, Node *z)
{
	Node *x = NULL;
	Node *y = NULL;

	if ((z->left == NULL) || (z->right == NULL)) {
		y = z;
	} else {
		y = bstree_successor(z);
	}

	if (y->left != NULL) {
		x = y->left;
	} else {
		x = y->right;
	}

	if (x != NULL) {
		x->parent = y->parent;
	}

	if (y->parent == NULL) {
		tree = x;
	} else if (y == y->parent->left) {
		y->parent->left = x;
	} else {
		y->parent->right = x;
	}

	if (y != z) {
		z->key = y->key;
	}

	if (y != NULL) {
		free(y);
	}

	return tree;
}

Node* delete_bstree(BSTree tree, Type key)
{
	Node *z;

	if ((z = bstree_search(tree, key)) != NULL) {
		tree = bstree_delete(tree, z);
	}

	return tree;
}


void print_bstree(BSTree tree, Type key, int direction)
{
	if (tree != NULL) {
		if (direction == 0) {
			printf("%2d is root\n", tree->key);
		} else {
			printf("%2d is %2d's %6s child\n",
					tree->key, key,
					direction==1?"right":"left");
		}

		print_bstree(tree->left, tree->key, -1);
		print_bstree(tree->right, tree->key, 1);
	}
}

void destroy_bstree(BSTree tree)
{
	if (tree == NULL) {
		return;
	}

	if (tree->left != NULL) {
		destroy_bstree(tree->left);
	}

	if (tree->right != NULL) {
		destroy_bstree(tree->right);
	}

	free(tree);
}
