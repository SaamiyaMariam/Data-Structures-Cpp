// Data Structures Lab 15
// Saamiya Mariam   20i-0612    CS-A
// AVL TREE
// each node's height should be either -1, 0 or 1
#include <iostream>
#include "Node.cpp"
using namespace std;



class AVL
{
public:
	Node* root;


	int max(int x, int y)
	{
		return (x > y) ? x : y;

	}

	Node* Insert(Node* temp, int da)
	{
		if (temp == NULL)
		{
			return (newNode(da));
		}
		if (da < temp->data)
			temp->left = Insert(temp->left, da);
		else if (da > temp->data)
			temp->right = Insert(temp->right, da);
		else
			return temp;

		temp->height = max(Height(temp->left), Height(temp->right)) + 1;
		return temp;

	}

	Node* newNode(int da)
	{
		Node* node = new Node;
		node->data = da;
		node->left = NULL;
		node->right = NULL;
		node->height = 1;

		return node;
	}

	int Height(Node* n)
	{
		if (n == NULL)
			return -1;
		else
		{
			int Lheight = Height(n->left);
			int Rheight = Height(n->right);

			if (Lheight > Rheight)
				return(Lheight + 1);
			else
				return (Rheight + 1);
		}

	}

	Node* RotateRight(Node* n)
	{
		Node* nR = n->right;
		Node* nL = n->left;

		//rotating right
		///left child's right becomes your node
		//node's left child becomes node's right child
		nL->right = n;
		n->left = nR;

		n->height = max(Height(n->left), Height(n->right)) + 1;

		nR->height = max(Height(nL->left), Height(nL->left)) + 1;

		return nR;

	}

	Node* RotateLeft(Node* n)
	{
		Node* nR = n->right;
		Node* nL = nR->left;

		// Rotating left
		nR->left = n;
		n->right = nL;

		n->height = max(Height(n->left), Height(n->right)) + 1;

		nR->height = max(Height(nR->left), Height(nR->right)) + 1;

		return nR;

	}

	bool Balance(Node* n)
	{
		int RHeight = Height(n->right);
		int LHeight = Height(n->left);

		if (abs(LHeight - RHeight) <= 1)
			return true;
		else
			return false;

	}

	void InorderDisplay(Node* root)
	{
		if (root == NULL)
		{
			return;

		}
		else
		{
			InorderDisplay(root->left);
			cout << root->data << " ";
			InorderDisplay(root->right);
		}
	}

	void level(Node* root, int x, int* arr, int c)
	{
		if (root == NULL)
			return;
		else if (x == 1)
		{
			arr[c] = root->data;
			cout << arr[c] << " ";
			c++;
		}
		else if (x > 1)
		{
			level(root->left, x - 1, arr, c);
			level(root->right, x - 1, arr, c);
		}

	}

	void BreadthFS(Node* rt)
	{
		int* arr = new int[12];
		int c = 0;
		int ht = Height(rt);
		for (int i = 0; i < ht; i++)
		{
			level(rt, i, arr, c);
		}

	}

};


///////// part c
//Implementing an AVL tree in array format is faster rather than nodes as it requires less operations
//whereas in tree format we'll need to perform rotations to sort it