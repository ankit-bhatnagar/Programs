// TODO: Correct for equal in left

#include <iostream>
#include <cstdlib>

#include "BinaryTree.h"
#include "myqueue.h"

using namespace std;

/* Binary Tree */
clBinaryTree::clBinaryTree() {
	headPtr = NULL;
}

treeNode_t * clBinaryTree::createNode(int data) {
	treeNode_t * temp = (treeNode_t *)malloc(sizeof(treeNode_t));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
}

treeNode_t * clBinaryTree::GetHeadPtr() {
	return headPtr;
}

void clBinaryTree::InsertElement(int data) {
	MyQueue elemQueue(100);
	treeNode_t * temp;

	if (headPtr == NULL) {
		headPtr = createNode(data);
		return;
	}

	elemQueue.enqueue(headPtr);
	while (!elemQueue.isQueueEmpty()) {
		temp = (treeNode_t *)elemQueue.dequeue();
		if (temp->left == NULL) {
			temp->left = createNode(data);
			break;
		} else if (temp->right == NULL) {
			temp->right = createNode(data);
			break;
		}

		if (temp->left) {
			elemQueue.enqueue(temp->left);
		}
		if (temp->right) {
			elemQueue.enqueue(temp->right);
		}
	}

	elemQueue.deleteQueue();
}

void clBinaryTree::TraverseLevelOrder() {
	MyQueue elemQueue(100);
	treeNode_t * temp;

	if (headPtr == NULL)
		return;

	cout << "Level Order Traversal" << endl;

	elemQueue.enqueue(headPtr);
	while(!elemQueue.isQueueEmpty()) {
		temp = (treeNode_t *)elemQueue.dequeue();
		cout << temp->data << endl;

		if (temp->left) {
			elemQueue.enqueue(temp->left);
		}
		if (temp->right) {
			elemQueue.enqueue(temp->right);
		}
	}

	elemQueue.deleteQueue();
}

/* Binary Search Tree */
clBinarySearchTree::clBinarySearchTree() {
	clBinarySearchTree::headPtr = NULL;
}

/* Binary tree from sorted Array */
clBinarySearchTree::clBinarySearchTree(int * array, int left, int right) {
	clBinarySearchTree::headPtr = NULL;

	headPtr = CreateTreeFromArray(array, left, right);
}

treeNode_t * clBinarySearchTree::createNode(int data) {
	treeNode_t * new_node = (treeNode_t*)malloc(sizeof(treeNode_t));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

/* Binary tree from Array */
treeNode_t * clBinarySearchTree::CreateTreeFromArray(int * array, int left, int right) {
	if (left > right)
		return NULL;
	int mid = (left + right)/2;
	treeNode_t * new_node = createNode(array[mid]);
	new_node->left = CreateTreeFromArray(array, left, mid - 1);
	new_node->right = CreateTreeFromArray(array, mid + 1, right);
	return new_node;
}

treeNode_t * clBinarySearchTree::GetHeadPtr() {
	return headPtr;
}

void clBinarySearchTree::InsertElementInternal(treeNode_t ** head, int data) {
	if (*head == NULL) {
		*head = createNode(data);
	} else {
		if (data <= (*head)->data) {
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

/* Balanced Tree Check */
int clBinarySearchTree::CheckBalancedHeight(treeNode_t * head) {
	if (head == NULL)
		return 0;

	int leftHeight = CheckBalancedHeight(head->left);
	if (leftHeight == -1)
		return -1;

	int rightHeight = CheckBalancedHeight(head->right);
	if (rightHeight == -1)
		return -1;

	if (abs(leftHeight - rightHeight) > 1)
		return -1;
	else
		return max(leftHeight, rightHeight) + 1;
}

void clBinarySearchTree::PrintBalanced() {
	if (CheckBalancedHeight(headPtr) == -1)
		cout << "Not Balanced" << endl;
	else
		cout << "Balanced" << endl;
}

/* Binary Tree To list */
vector< list<treeNode_t *> > clBinarySearchTree::BinaryTreeToList() {
	vector< list<treeNode_t *> > results;
	list<treeNode_t *> * current;
	list<treeNode_t *> * parents;
	int count = 1;

	current = new list<treeNode_t *>;
	current->push_back(headPtr);

	while(current->size() != 0) {
		results.push_back(*current);
		parents = current;
		current = new list<treeNode_t *>;

		for (list<treeNode_t *>::iterator i = parents->begin(); i != parents->end(); i++) {
			if ((*i)->left) {
				current->push_back((*i)->left);
			}
			if ((*i)->right) {
				current->push_back((*i)->right);
			}
		}
		count++;
	}

	cout << "Total Levels " << count << endl;

	return results;
}