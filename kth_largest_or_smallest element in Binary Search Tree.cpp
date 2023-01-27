/**
 * My Approach:
 * 1. First traverse the inorder and push them into a vector
 * 2. return vector[k-1] element
 * 3. Time complexity : O(N)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root,ans);
        return ans[k-1];
    }
    void inorder(TreeNode* root, vector<int>&ans)
    {
        if(root == NULL)
        {
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
};

/*
* Optimised Solution:
 1. First traversing to the left most leaf node and pushing them to a stack until we reach null.
 2. Then poping the stack and checking whether it is required solution or not, if not then moving to the right of the popped out node
 3. Time complexity: o(log(N)+k)
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>stack;
        while(1)
        {
            while(root)
            {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if(--k == 0) return root->val;
            root = root->right;
        }
    }
};