#include <iostream>
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if(preorder == nullptr || inorder == nullptr || length <= 0)
	{
		return nullptr;
	}
	return ConstructCore(preorder, preorder + length - 1, 
		inorder, inorder + length - 1)；
}


BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder,
	int* startInorder, int* endInorder)
	{
		int rootValue = startPreorder[0];
		BinaryTreeNode* root = new BinaryTreeNode();
		root->m_nValue = rootValue;
		root->m_pLeft = root->m_pRight = nullptr;
		if(startPreorder == endPreorder)
		{
			if(startInorder == endInorder && *startPreorder == *startInorder)
				//the tree(or the subbranch) has only one node
				return root;
			else
				throw std::exception("Invalid input.");
		}
		//find root in inorder travesal
		int *rootInorder = startInorder;
		while(rootInorder <= endInorder && *rootInorder != rootValue)
			++rootInorder;

		if(rootInorder == endInorder && *rootInorder != rootValue)
			//root node not found in inorder travesal
			throw std::exception("Invalid input.");

		int leftLength = rootInorder - startInorder;
		int* lefetPreorderEnd = startPreorder + leftLength;
		if(leftLength > 0)
		{
			//construct left branch
			root->m_pLeft = ConstructCore(startPreorder + 1, lefetPreorderEnd, startInorder, rootInorder - 1);
		}
		if(leftLength < endPreorder - startPreorder)
			//has right branch
		{
			root->m_pRight = ConstructCore(lefetPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
		}

		return root;
	}
