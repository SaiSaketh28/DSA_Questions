. Postorder Traversal Iterative approach using two stacks:

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        if(root == NULL)
        {
            return postorder;
        }
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        st1.push(root);
        while(!st1.empty())
        {
            TreeNode* temp = st1.top();
            st1.pop();
            if(root->left)
            {
                st1.push(root->left);
            } 
            if(root->right)
            {
                st1.push(root->right);
            }
            postorder.push_back(temp->val);
        }
        // while(!st2.empty())
        // {
        //     TreeNode* dump = st2.top();
        //     st2.pop();
        //     postorder.push_back(dump->val);
        // }
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }
};