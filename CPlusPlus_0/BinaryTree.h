/* Node of the tree */
#include <cstddef>

typedef struct _treeNode_t {
	int data;
	struct _treeNode_t * left;
	struct _treeNode_t * right;
} treeNode_t;

class clBinarySearchTree {
private:
	treeNode_t * headPtr;
	treeNode_t * createNode(int data);
	void InsertElementInternal(treeNode_t ** head, int data);
	treeNode_t * DeleteElementInternal(treeNode_t * head, int data);
	treeNode_t * SearchElementInternal(treeNode_t * head, int data);
	void TraversePreOrderInternal(treeNode_t * head);
	void TraverseInOrderInternal(treeNode_t * head);
	void TraversePostOrderInternal(treeNode_t * head);
public:
	clBinarySearchTree();
	void InsertElement(int data);
	void DeleteElement(int data);
	treeNode_t * SearchElement(int data);
	void TraversePreOrder();
	void TraverseInOrder();
	void TraversePostOrder();
};