/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
2
/ \
1   3
Output: true
Example 2:

5
/ \
1   4
/ \
3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
is 5 but its right child's value is 4.
*/


/**
* Definition for a binary tree node.
* 
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	
};
class Solution {
public:
	bool isValidBSTHelper(TreeNode* root, TreeNode* &prev) {
		if (root != nullptr)
		{
			if (!isValidBSTHelper(root->left, prev))
				return false;

			if (prev != nullptr && prev->val >= root->val)
				return false;

			prev = root;

			return(isValidBSTHelper(root->right, prev));
		}
		return true;
	}

	bool isValidBST(TreeNode* root) {
		TreeNode* prev = nullptr;
		return isValidBSTHelper(root, prev);
	}
};
