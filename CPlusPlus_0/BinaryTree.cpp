// TODO: Correct for equal in left

#include <iostream>
#include <cstdlib>
#include "BinaryTree.h"

using namespace std;

clBinarySearchTree::clBinarySearchTree() {
	clBinarySearchTree::headPtr = NULL;
}

treeNode_t * clBinarySearchTree::createNode(int data) {
	treeNode_t * new_node = (treeNode_t*)malloc(sizeof(treeNode_t));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

void clBinarySearchTree::InsertElementInternal(treeNode_t ** head, int data) {
	if (*head == NULL) {
		*head = createNode(data);
	} else {
		if (data < (*head)->data) {
			InsertElementInternal(&(*head)->left, data);
		}
		else {
			InsertElementInternal(&(*head)->right, data);
		}
	}
}

/* Insertion will happen in order */
void clBinarySearchTree::InsertElement(int data) {
	InsertElementInternal(&headPtr, data);
}

treeNode_t * clBinarySearchTree::DeleteElementInternal(treeNode_t * head, int data) {
	if (head == NULL)
		return NULL;

	if (data < head->data) {
		head->left = DeleteElementInternal(head->left, data);
		return head;
	}
	else if (data > head->data) {
		head->right = DeleteElementInternal(head->right, data);
		return head;
	}
	else {
		if (head->left == NULL && head->right == NULL) {
			free(head);
			return NULL;
		} else if (head->left == NULL) {
			treeNode_t * temp = head->right;
			free(head);
			return temp;
		} else if (head->right == NULL) {
			treeNode_t * temp = head->left;
			free(head);
			return temp;
		} else {
			treeNode_t * inorderSuccessor = head->right;
			treeNode_t * inorderSuccessorParent = head;
			while (inorderSuccessor->left != NULL) {
				inorderSuccessorParent = inorderSuccessor;
				inorderSuccessor = inorderSuccessor->left;
			}

			head->data = inorderSuccessor->data;
			inorderSuccessorParent->left = inorderSuccessor->right;
			free(inorderSuccessor);
			return head;
		}
	}
}

void clBinarySearchTree::DeleteElement(int data) {
	DeleteElementInternal(headPtr, data);
}

treeNode_t * clBinarySearchTree::SearchElementInternal(treeNode_t * head, int data) {
	if (head == NULL) {
		return NULL;
	}

	if (head->data == data) {
		return head;
	} else {
		if (data < head->data) {
			return SearchElementInternal(head->left, data);
		} else {
			return SearchElementInternal(head->right, data);
		}
	}
}

treeNode_t * clBinarySearchTree::SearchElement(int data) {
	return SearchElementInternal(headPtr, data);
}

void clBinarySearchTree::TraversePreOrderInternal(treeNode_t * head) {
	if (head == NULL)
		return;
	cout << head->data << endl;
	TraversePreOrderInternal(head->left);
	TraversePreOrderInternal(head->right);
}

void clBinarySearchTree::TraversePreOrder() {
	cout << "Pre Order" << endl;
	TraversePreOrderInternal(headPtr);
}

void clBinarySearchTree::TraverseInOrderInternal(treeNode_t * head) {
	if (head == NULL)
		return;
	TraverseInOrderInternal(head->left);
	cout << head->data << endl;
	TraverseInOrderInternal(head->right);
}

void clBinarySearchTree::TraverseInOrder() {
	cout << "In Order" << endl;
	TraverseInOrderInternal(headPtr);
}

void clBinarySearchTree::TraversePostOrderInternal(treeNode_t * head) {
	if (head == NULL)
		return;
	TraversePostOrderInternal(head->left);
	TraversePostOrderInternal(head->right);
	cout << head->data << endl;
}

void clBinarySearchTree::TraversePostOrder() {
	cout << "Post Order" << endl;
	TraversePostOrderInternal(headPtr);
}

int main() {
	clBinarySearchTree aTree;
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
}