// Searching in a Binary Search Tree 
// Time Complexity - O(h) :: h-height of the root containing the value
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if(root == NULL)
        {
            return NULL;
        }
        if(root->val == val)
        {
            return root;
        }
        if(val>root->val)
        {   root = root->right;
            return searchBST(root,val);
        }
        if(val<root->val)
        {   root = root->left;
            return searchBST(root,val);
        }
        return NULL;
    }
};