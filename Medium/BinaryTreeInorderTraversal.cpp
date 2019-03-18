/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
1
\
2
/
3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

/*
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 11.3 MB, less than 5.11% of C++ online submissions for Binary Tree Inorder Traversal.
*/

#include <vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
	vector<int> inorderTraversalHelper(TreeNode* root, vector<int> & output) {
		if (root != nullptr)
		{
			inorderTraversalHelper(root->left, output);
			output.push_back(root->val);
			inorderTraversalHelper(root->right, output);
		}
		return output;
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> output;
		return inorderTraversalHelper(root, output);
	}
};
