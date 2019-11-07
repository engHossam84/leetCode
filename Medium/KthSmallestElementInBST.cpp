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
    void inOrderTraverse(TreeNode * root, vector<int> &TreeElement)
    {
        if(root != nullptr)
        {
            inOrderTraverse(root->left, TreeElement);
            TreeElement.push_back(root->val);
             inOrderTraverse(root->right, TreeElement);
            
        }
        
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> TreeElement;
        inOrderTraverse(root, TreeElement);
        return TreeElement[k-1];
        
    }
};
