/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
[1,null,3,2],
[3,2,null,1],
[3,1,null,null,2],
[2,1,3],
[1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3
*/


/*
The optimal substructure is that for any BST with nodes 1 to n, pick i-th node as root, then the left subtree will contain nodes from 1 to (i-1), and the right subtree will contain nodes from (i+1) to n

TreeList void genAllBST(int high,int low) {

	if(high>=low) {
		currList = []
		for(int i=low;i<=high;i++) {
			curr = new Node(i);
			leftList = genAllBST(i-1,low);
			rightList = genAllBST(high,i+1);
			TreeList c = connect(curr,leftList,rightList);
			currList.add(c);
		}

		return(currList);

	}

	return(null);
}

genAllBST(n,1);


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
private:
	vector<TreeNode*> helper(int start, int end) {
		vector<TreeNode*> res;
		if (start > end) {
			res.push_back(nullptr);
			return res;
		}
		for (int i = start; i <= end; i++) {
			vector<TreeNode*> lefts = helper(start, i - 1);
			vector<TreeNode*> rights = helper(i + 1, end);
			for (int j = 0; j < (int)lefts.size(); j++) {
				for (int k = 0; k < (int)rights.size(); k++) {
					TreeNode* root = new TreeNode(i);
					root->left = lefts[j];
					root->right = rights[k];
					res.push_back(root);
				}
			}
		}
		return res;
	}
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return vector<TreeNode*>(0);
		return helper(1, n);
	}
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
class Solution2 {
public:

	bool isIdenticalHelper(TreeNode* t1, TreeNode* t2)
	{
		// cout << "Enter isIdenticalHelper"<< endl;
		if (t1 == nullptr && t2 == nullptr)
			return true;

		if (t1 == nullptr || t2 == nullptr)
			return false;

		// cout << "t1 = " <<t1->val <<" , t2 = " << t2->val << endl;
		return(t1->val == t2->val && isIdenticalHelper(t1->left, t2->left) && isIdenticalHelper(t1->right, t2->right));
	}

	bool isIdentical(TreeNode* t1, vector<TreeNode*> &output)
	{
		// cout << "Enter isIdentical"<< endl;
		for (auto tree : output)
		{
			if (t1->val == tree->val && isIdenticalHelper(t1, tree))
				return true;
		}
		return false;
	}

	void insert(int val, TreeNode* &root)
	{
		if (root == nullptr)
		{
			root = new TreeNode(val);
		}
		else
		{
			if (val < root->val)
				insert(val, root->left);
			else if (val > root->val)
				insert(val, root->right);
		}
	}

	vector<TreeNode*> generateTrees(int n) {
		vector<int> input;
		vector<TreeNode*> output;
		if (n == 0)  return output;
		for (int i = 1; i <= n; i++)
		{
			input.push_back(i);
		}

		do
		{

			TreeNode * root = nullptr;
			for (int i = 0; i < n; i++)
			{
				//     cout << input[i] << " ";
				insert(input[i], root);
			}
			// cout << endl;
			if (output.size() == 0)
				output.push_back(root);
			else
			{
				bool matchFound = isIdentical(root, output);
				if (!matchFound)
				{
					output.push_back(root);
				}
				else
				{
					//cout << "matchFound = " << matchFound << endl;
				}
			}

		} while (next_permutation(input.begin(), input.end()));

		return output;
	}
};

void main()
{
	Solution s;
	s.generateTrees(3);
}


