// TODO: Correct for equal in left

#include <iostream>
#include <cstdlib>

#include "BinaryTree.h"

/* To check if its BST or not */
/* need the lowest -ve value here */
bool IsBSTRecursive(treeNode_t * head, int * last) {
	if (head == NULL) {
		*last = -1;
		return true;
	}

	if (!IsBSTRecursive(head->left, last))
		return false;

	if (*last > head->data)
		return false;

	*last = head->data;

	if (!IsBSTRecursive(head->right, last))
		return false;

	return true;
}

bool IsBST(treeNode_t * head) {
	/* One way, do Inorder and its sorted */
	int prev;
	cout << IsBSTRecursive(head, &prev) << endl;
}

int main() {
	clBinarySearchTree aTree;
	clBinaryTree anotherTree;

	aTree.InsertElement(10);
	aTree.InsertElement(6);
	aTree.InsertElement(1);
	aTree.InsertElement(2);
	aTree.InsertElement(14);
	aTree.InsertElement(13);
	aTree.InsertElement(15);
	aTree.InsertElement(18);
	aTree.InsertElement(21);
	//aTree.TraversePreOrder();
	aTree.TraverseInOrder();
	//aTree.TraversePostOrder();
	aTree.DeleteElement(10);
	aTree.TraverseInOrder();

	/* Binary Tree with level order */
	anotherTree.InsertElement(1);
	anotherTree.InsertElement(12);
	anotherTree.InsertElement(14);
	anotherTree.InsertElement(2);
	anotherTree.InsertElement(90);
	anotherTree.InsertElement(76);
	anotherTree.InsertElement(4);
	anotherTree.InsertElement(0);
	anotherTree.InsertElement(8);
	anotherTree.TraverseLevelOrder();

	/* Balanced Check */
	clBinarySearchTree myTree;
	myTree.InsertElement(10);
	myTree.InsertElement(6);
	myTree.InsertElement(8);
	myTree.InsertElement(1);
	myTree.InsertElement(14);
	myTree.InsertElement(12);
	myTree.InsertElement(16);
	myTree.PrintBalanced();
	aTree.PrintBalanced();

	/* Binary Tree from Array */
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	clBinarySearchTree mySweetTree(array, 0, 9);
	mySweetTree.TraverseInOrder();

	/* Lists from Binary Tree */
	cout << "Tree List" << endl;
	vector< list<treeNode_t *> > ourLists = mySweetTree.BinaryTreeToList();
	/* traverse first 2 lists */
	for (list<treeNode_t *>::iterator i = ourLists[0].begin(); i != ourLists[0].end(); i++) {
		cout << (*i)->data << endl;
	}

	/* Check if binary tree is BST or not */
	IsBST(mySweetTree.GetHeadPtr());
}