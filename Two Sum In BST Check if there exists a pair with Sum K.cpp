// My Approach:
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        set<int>ans;
        inorder(root,ans);
        for(auto it=ans.begin();it != ans.end();it++)
        {
            if(ans.find(k-*it) != ans.end() && ans.find(k-*it) != it)
            {
                return true;
            }
        }
        return false;
    }
    void inorder(TreeNode* root,set<int>&ans)
    {
        if(root == NULL)
        {
            return;
        }
        inorder(root->left,ans);
        ans.insert(root->val);
        inorder(root->right,ans);
    }
};
// Optimised Approach:
