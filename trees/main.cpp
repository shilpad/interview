/*
 * main.cpp
 *
 *  Created on: Jul 19, 2014
 *      Author: rudolpharaujo
 */

/* 13.	Given a binary tree such that there are i nodes at the ith level. Compute the heaviest path cost
             1
           /    \
       2        3
     /    \   /      \
4          5         6
*/


#include <stddef.h>
#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

struct node
{
	node*	left;
	node*	right;
	int		value;
};

class btree
{
private:
	node *root;

	void insert (node* node, int key);
	void search (int key, node *leaf);
	void create_node (node **leaf, int key);

	void print (node *leaf, bool &isValidBST, int &min);

	void printUsingBreadthFirstTraversal (node *leaf);
	void printUsingDepthFirstTraversal (node *leaf);
	void destroy_tree (node* leaf);
	int heightOfTree (node *leaf);
	bool isBalanced (node *leaf);
	void printAllPathOfTree (vector<int> vecNodeValue, node *leaf);
	unsigned int getLeafCount (node *leaf);
	void findLowestCommonAncestor (node *root, int value1, int value2);
	void printUsingDepthFirstSearchAlsoCalledPreOrder (node *leaf);
	void findSmallestElement (node *leaf, int &min);
	node *findLowestCommonAncestorOfNonBST (node *leaf, int value1, int value2);
	node *flipTree (node *leaf);

public:
	btree ();
	~btree();

	void insert (int key);
	void search (int key);
	void deleteNode (int key);
	void print ();
	void printUsingDepthFirstTraversal ();
	int heightOfTree ();
	bool isBalanced ();
	void destroy_tree ();
	void printAllPathOfTree ();
	unsigned int getLeafCount ();
	void findLowestCommonAncestor(int value1, int value2);
	int findSmallestElement ();
	void findLowestCommonAncestorOfNonBST (int value1, int value2);
	void flipTree ();
};

void btree::destroy_tree(node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree (leaf->left);
		destroy_tree (leaf->right);
		delete leaf;
	}
}

void btree::destroy_tree ()
{
	destroy_tree (root);
}

btree::btree ()
{
	root = NULL;
}

btree::~btree()
{
	destroy_tree (root);
}

void btree::create_node (node **leaf, int key)
{
	*leaf = new node ();
	(*leaf)->left = NULL;
	(*leaf)->right = NULL;
	(*leaf)->value = key;
}

void btree::insert(node* leaf, int key)
{
	if (key > leaf->value)
	{
		if (leaf->right != NULL)
			insert (leaf->right, key);
		else
		{
			create_node (&(leaf->right), key);
			/*leaf->right = new node ();
			leaf->right->left = NULL;
			leaf->right->right = NULL;
			leaf->right->value = key;*/
		}
	} else if (key < leaf->value)
	{
		if (leaf->left != NULL)
			insert (leaf->left, key);
		else
		{
			create_node (&(leaf->left), key);
			/*leaf->left = new node ();
			leaf->left->left = NULL;
			leaf->left->right = NULL;
			leaf->left->value = key;*/
		}
	}
}

void btree::insert(int key)
{
	if (root == NULL)
	{
		root = new node ();
		root->left = NULL;
		root->right = NULL;
		root->value = key;
	}
	else
	{
		insert (root, key);
	}
}

//bfs & dfs
// in-order traversal
//void btree::print (node *leaf, bool &isValidBST)
//Modifying print signature to return minimum element
// However traversing the entire tree to find smallest element is an overkill
// Writing a different method to get the min
void btree::print (node *leaf, bool &isValidBST, int &min)
{
	static int prevNodeValue  = INT_MIN;

	if (leaf == NULL)
	{
		return;
	}

	print (leaf->left, isValidBST, min);

	// This extra block is to check if it is a valid BST
	// i.e. is current node value greater than the previous one
	if (leaf->value > prevNodeValue)
	{
		isValidBST = true;
	}

	if (leaf->value < min)
		min = leaf->value;

	prevNodeValue = leaf->value;


	cout << leaf->value;
	print (leaf->right, isValidBST, min);
}

//5423769
void btree::printUsingDepthFirstSearchAlsoCalledPreOrder (node *leaf)
{
	if (leaf == NULL)
		cout << "#";
	else
	{
	cout << leaf->value;
	printUsingDepthFirstSearchAlsoCalledPreOrder (leaf->left);
	printUsingDepthFirstSearchAlsoCalledPreOrder (leaf->right);
	}
}

void btree::printUsingDepthFirstTraversal (node *root)
{
	if (root == NULL)
		return;

	stack <node*> s;
	set<int> visited;

	for (s.push(root); !s.empty(); )
	{
		node *tmp = s.top();
		s.pop();

		if (visited.find (tmp->value) != visited.end())
			continue; // already visited

		cout << tmp->value;
		visited.insert (tmp->value);

		if (tmp->left != NULL)
			s.push(tmp->left);

		if (tmp->right != NULL)
			s.push (tmp->right);
	}
}

void btree::printUsingDepthFirstTraversal ()
{
	printUsingDepthFirstTraversal (root);
}

void btree::printUsingBreadthFirstTraversal (node *root)
{
	queue<node*> q;
	set<int> visited;

	if (root == NULL)
		return;

	for (q.push(root); !q.empty(); q.pop())
	{
		node* tmp = q.front();

		if (visited.find (tmp->value) != visited.end())
				continue; // already visited

		cout << tmp->value << " ";
		visited.insert (tmp->value);

		if (tmp->left)
			q.push (tmp->left);

		if (tmp->right)
			q.push (tmp->right);
	}
}

void btree::printAllPathOfTree (vector<int> vecNodeValue, node *leaf)
{
	if (leaf == NULL)
		return;

	vecNodeValue.push_back(leaf->value);

	if (leaf->left == NULL & leaf->right == NULL)
	{
		//print the path since this is the leaf node
		for (vector<int>::iterator it = vecNodeValue.begin (); it != vecNodeValue.end (); ++it)
		{
			cout << *it << "->";
		}

		cout << endl;
		return;
	}

	printAllPathOfTree(vecNodeValue, leaf->left);
	printAllPathOfTree(vecNodeValue, leaf->right);
}

void btree::printAllPathOfTree()
{
	vector<int> vecNodeValue;
	printAllPathOfTree (vecNodeValue, root);
}

void btree::print ()
{
	// traverse in-order & also check the integrity of the tree
	// if the values of the nodes are in ascending order, then it is a valid BST
	bool isValidBST = false;
	cout << "Print using in-order traversal....\n";
	int min;
	print (root, isValidBST, min);

	cout << "\n This tree is a valid BST:"<< isValidBST << endl;
	cout << "Smallest element in this BST is = " << min << endl;

	cout << "\nPrint using BFS so that we get nodes per level !....\n";
	printUsingBreadthFirstTraversal (root); // prints nodes in level order !

	cout << "\nPrint using DFS  !....\n";
	printUsingDepthFirstTraversal (root);

	cout << "\nPrint using DFS which is same as pre-order\n";
	printUsingDepthFirstSearchAlsoCalledPreOrder (root); //DFS and Pre-order are same !
}

void btree::search (int key, node* leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->value)
		{
			cout << key << " exists in the tree \n";
		}
		else if (key > leaf->value)
			search (key, leaf->right);
		else
			search (key, leaf->left);
	}
}

void btree::search (int key)
{
	if (root != NULL)
	{
		search (key, root);
	}
}

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int btree::heightOfTree (node *leaf)
{
	if (leaf == NULL)
		return 0;
	else
	{
		int lheight = heightOfTree (leaf->left);
		int rheight = heightOfTree (leaf->right);

		if (lheight > rheight)
			return (lheight + 1);
		else
			return (rheight + 1);
	}
}

int btree::heightOfTree ()
{
	int height = heightOfTree (root);
	cout << "Height of tree is " << height << endl;

	return height;
}

bool btree::isBalanced(node *leaf)
{
	/*
	 * An empty tree is height-balanced. A non-empty binary tree T is balanced if:
	1) Left subtree of T is balanced
	2) Right subtree of T is balanced
	3) The difference between heights of left subtree and right subtree is not more than 1.
	 */

	if (leaf == NULL)
		return true;

	int lht = heightOfTree (leaf->left);
	int rht = heightOfTree (leaf->right);
	//cout << "Height of left tree = " << lht << " and right tree = " << rht << endl;

	if (abs(lht - rht) <= 1 && isBalanced (leaf->left) && isBalanced (leaf->right))
		return true;
	else
		return false;
}

bool btree::isBalanced()
{
	return (isBalanced (root));
}

unsigned int btree::getLeafCount (node *leaf)
{
	if (leaf == NULL)
		return 0;
	else if (leaf->left == NULL & leaf->right == NULL)
			return 1; // leaf node
	else
		return (getLeafCount (leaf->left) + getLeafCount (leaf->right));
}

unsigned int btree::getLeafCount ()
{
	return (getLeafCount (root));
}

void btree::findLowestCommonAncestor (node *root, int value1, int value2)
{
	node *tmp = root;

	while (tmp != NULL)
	{
		int value = tmp->value;
		if ((value1 < value) && (value2 < value))
			tmp = tmp->left;
		else if ((value1 > value) && (value2 > value))
			tmp = tmp->right;
		else
		{
			cout << value << " is the lowest common ancestor of " << value1 <<  " and " << value2 << endl;
			return;
		}
	}
}

void btree::findLowestCommonAncestor (int value1, int value2)
{
	findLowestCommonAncestor (root, value1, value2);
}

node *btree::findLowestCommonAncestorOfNonBST (node *leaf, int value1, int value2)
{
	if (!leaf) return NULL;

	if (leaf->value == value1 || leaf->value == value2) return leaf;

	node *L = findLowestCommonAncestorOfNonBST (leaf->left, value1, value2);
	node *R = findLowestCommonAncestorOfNonBST (leaf->right, value1, value2);

	if (L && R) return leaf; // if value1 and value2 are on both sides
	return (L ? L : R); // either one of value1, value2 is on one side or OR value1, value2 is
						// not in the L&R subtrees
}

void btree::findLowestCommonAncestorOfNonBST (int value1, int value2)
{
	node *ancestor = findLowestCommonAncestorOfNonBST (root, value1, value2);
	cout << "LCA of binary tree is " << ancestor->value << endl;
}

void btree::findSmallestElement (node *leaf, int &min)
{
	if (leaf == NULL)
		return;

	if (leaf->left == NULL)
		min = leaf->value;
	else
		findSmallestElement (leaf->left, min);
}

int btree::findSmallestElement ()
{
	int  min;
	findSmallestElement (root, min);

	return min;
}

node *btree::flipTree (node *leaf)
{
	if (leaf == NULL)
		return NULL;

	if (leaf->left == NULL && leaf->right == NULL)
		return leaf;

	cout << "calling flipTree on leaf=" << leaf->value << "leaf->left=" << leaf->left->value << endl;
	node *newRoot = flipTree (leaf->left);

	cout << leaf->value << endl;

    leaf->left->left = leaf->right;
    leaf->left->right = leaf;
    leaf->left = NULL;
    leaf->right = NULL;

    return newRoot;
}

void btree::flipTree ()
{
	root = flipTree (root);
}

/*
 * 							 5
 * 							/\
 * 						   4  7
 * 						  /  / \
 * 						 2 	6   9
 * 						 \
 * 						  3
 */

int main ()
{
	btree objTree;

	objTree.insert (5);
	objTree.insert (4);
	objTree.insert (2);
	objTree.insert (3);
	objTree.insert (7);
	objTree.insert (6);
	objTree.insert (9);

	objTree.print ();

	//objTree.flipTree();
	//cout << "After flipTree ----- \n";
	//objTree.print ();

	cout << endl;

	objTree.search (7);

	objTree.heightOfTree();

	cout << "true = " << true << " false = " << false << endl;

	cout << "This tree is balanced = " << objTree.isBalanced () << endl;

	// balancing a tree - http://stackoverflow.com/questions/14001676/balancing-a-bst, by amit

	objTree.printAllPathOfTree();

	cout << "Number of leaves in this tree is " << objTree.getLeafCount() << endl;

	objTree.findLowestCommonAncestor (6,9); // Only this function is non-recursive !!!

	cout << "Smallest element in this BST is=" << objTree.findSmallestElement() << endl;

	objTree.findLowestCommonAncestorOfNonBST (6,9); // i.e. just a binary tree
}



