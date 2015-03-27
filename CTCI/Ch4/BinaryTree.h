/* Node of the tree */
#include <cstddef>
#include <vector>
#include <list>

using namespace std;

typedef struct _treeNode_t {
	int data;
	struct _treeNode_t * left;
	struct _treeNode_t * right;
} treeNode_t;

class clBinaryTree {
private:
	treeNode_t * headPtr;
	treeNode_t * createNode(int data);
public:
	clBinaryTree();
	treeNode_t * GetHeadPtr();
	void InsertElement(int data);
	void TraverseLevelOrder();
};

class clBinarySearchTree {
private:
	treeNode_t * headPtr;
	treeNode_t * createNode(int data);
	treeNode_t * CreateTreeFromArray(int * array, int left, int right);
	void InsertElementInternal(treeNode_t ** head, int data);
	treeNode_t * DeleteElementInternal(treeNode_t * head, int data);
	treeNode_t * SearchElementInternal(treeNode_t * head, int data);
	void TraversePreOrderInternal(treeNode_t * head);
	void TraverseInOrderInternal(treeNode_t * head);
	void TraversePostOrderInternal(treeNode_t * head);
	int CheckBalancedHeight(treeNode_t * head);
public:
	clBinarySearchTree();
	clBinarySearchTree(int * array, int left, int right);
	treeNode_t * GetHeadPtr();
	void InsertElement(int data);
	void DeleteElement(int data);
	treeNode_t * SearchElement(int data);
	void TraversePreOrder();
	void TraverseInOrder();
	void TraversePostOrder();
	void PrintBalanced();
	vector< list<treeNode_t *> > BinaryTreeToList();
};