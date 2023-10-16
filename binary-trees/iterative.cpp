#include<bits/stdc++.h>
using namespace std;

/* binary tree node data structure to store data, and its left and right child */

struct treeNode
{
	int data;
	struct treeNode* leftNode;
	struct treeNode* rightNode;

// constructor to initialize data to the treeNode	
    treeNode (int data)
	{
		this->data = data;
		leftNode = rightNode = NULL;
	}
};

// funtion for iterative inorder traversal
void inOrderTraversal(struct treeNode *root)
{
	stack<treeNode *> treeStack;
	treeNode *currentNode = root;

	while (currentNode != NULL || treeStack.empty() == false)
	{
        //condition to check if the node is leftmost node 
		while (currentNode != NULL)
		{
			// step 3 of our algorithm
			treeStack.push(currentNode);
			currentNode = currentNode->leftNode;
		}
		
		currentNode = treeStack.top();
		treeStack.pop();
        // cout statement to print the node data
		cout << currentNode->data <<", ";
        
        // statement to process right subtree 
		currentNode = currentNode->rightNode;
	} 
}

int main()
{    //code to create the binary tree
	struct treeNode *root = new treeNode(1);
	root->leftNode = new treeNode(2);
	root->rightNode = new treeNode(3);
	root->leftNode->leftNode = new treeNode(4);
	root->leftNode->rightNode = new treeNode(5);
        root->rightNode->rightNode = new treeNode(6);
	inOrderTraversal(root); //function call
	return 0;
}

