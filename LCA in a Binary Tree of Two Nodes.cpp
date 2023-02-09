// My Approach:
//Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }
        vector<TreeNode*>temp1;
        vector<TreeNode*>temp2;
        path(root,temp1,p);
        path(root,temp2,q);
        TreeNode* commonnode;
        for(int i =0;i<min(temp1.size(),temp2.size());i++)
        {
            if(temp1[i] == temp2[i])
            {
                commonnode = temp1[i];
            }
        }
        return commonnode;
    }
    bool path(TreeNode* root,vector<TreeNode*>&temp1,TreeNode* p)
    {
        if(root == NULL)
        {
            return false;
        }
        temp1.push_back(root);
        if(root->val == p->val)
        {
            return true;
        }
        if(path(root->left,temp1,p) || path(root->right,temp1,p))
        {
            return true;
        }
        temp1.pop_back();
        return false;
    }
};

// Optimised Approach: https://takeuforward.org/data-structure/lowest-common-ancestor-for-two-given-nodes/