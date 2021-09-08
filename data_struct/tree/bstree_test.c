/**
 * c language: binary search tree
 *
 * @author
 * @date
 */

#include <stdio.h>
#include "bstree.h"

static int arr[] = {1, 5, 4, 3, 2, 6};
#define TBL_SIZE(a) ((sizeof(a) / sizeof(a[0])))

int main(void)
{
	int i, ilen;
	BSTree root = NULL;

	printf("== add one by one: ");
	ilen = TBL_SIZE(arr);
	for (i = 0; i < ilen; i++) {
		printf("%d ", arr[i]);
		root = insert_bstree(root, arr[i]);
	}

	printf("\n== pre-order: ");
	preorder_bstree(root);

	printf("\n== in-order: ");
	inorder_bstree(root);

	printf("\n== post-order: ");
	postorder_bstree(root);
	printf("\n");

	printf("== minimum: %d\n", bstree_minimum(root)->key);
	printf("== maximum: %d\n", bstree_maximum(root)->key);
	printf("== tree info: \n");
	print_bstree(root, root->key, 0);

	printf("\n== delete root: %d", arr[3]);
	root = delete_bstree(root, arr[3]);

	printf("\n== in-order: ");
	inorder_bstree(root);
	printf("\n");

	//destroy tree
	destroy_bstree(root);

	return 0;
}
