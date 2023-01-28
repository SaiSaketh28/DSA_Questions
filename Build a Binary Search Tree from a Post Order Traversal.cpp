// link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* temp;
        temp = root;
        for(int i=1;i<preorder.size();i++)
        {
            build(temp,preorder[i]);
        }
        return root;
    }
    TreeNode* build(TreeNode* temp,int val)
    {
        if(temp == NULL) 
        {  
             return temp = new TreeNode(val);
        }
        if(temp->val>val)  
        {  
             temp->left = build(temp->left,val);
        }
        else  
        {   
             temp->right = build(temp->right,val);
        }
        return temp;
    }
};

// Optimised Solution:
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
       return  build(preorder,i,INT_MAX);
    }
    TreeNode* build(vector<int>&preorder,int &i,int bound)
    {
        if(preorder[i]>bound || i == preorder.size()) return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder,i,root->val);
        root->right = build(preorder,i,bound);
        return root;
    }
};