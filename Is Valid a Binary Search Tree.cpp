/* My Approach: 
    1. First create inorder traversal in a vectror
    2. Now traverse the vector and check wether it is in ascending order
    3. Time Complexity: O(N)+O(N)
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
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i]>ans[i+1])
            {
                return false;
            }
            if(ans[i] == ans[i+1])
            {
                return false;
            }
        }
        return true;
    }
    void inorder(TreeNode* root,vector<int>&ans)
    {   if(root == NULL)
        {
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
};
/*Optimised Approach:
1. we pass max and min values in which the node value should lie 
2. Otherwise we return false*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isvalid(root,INT_MAX,INT_MIN);
    }
    bool isvalid(TreeNode* root,int max,int min)
    {
        if(root == NULL)
        {
            return true;
        }
        if(root->val>max || root->val<=min)
        {
            return false;
        }
        return isvalid(root->left,root->val,min)&&isvalid(root->right,max,root->val);
    }
};