/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its bottom-up level order traversal as:
[
[15,7],
[9,20],
[3]
]

*/

/**
* Definition for a binary tree node.*/
#include <vector>
#include <queue>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution {
 public:
	 int hight(TreeNode *root) {
		 if (!root) return 0;
		 return 1 + max(hight(root->left), hight(root->right));
	 }

	 vector<vector<int>> levelOrderBottom(TreeNode* root) {
		 queue<TreeNode *> nodeQueue;
		 int h = hight(root);
		 vector<vector<int>> output(h, vector<int>{});
		 if (root)
		 {

			 nodeQueue.push(root);
			 int numOfNodes = 0;
			 while (!nodeQueue.empty())
			 {
				 numOfNodes = nodeQueue.size();
				 vector<int> levelNodes;
				 while (numOfNodes > 0)
				 {
					 TreeNode * tmpNode = nodeQueue.front();
					 levelNodes.push_back(tmpNode->val);
					 nodeQueue.pop();

					 if (tmpNode->left != nullptr)
						 nodeQueue.push(tmpNode->left);
					 if (tmpNode->right != nullptr)
						 nodeQueue.push(tmpNode->right);
					 numOfNodes--;
				 }
				 output[h - 1] = levelNodes;
				 h--;
			 }
		 }

		 return output;
	 }
 };
