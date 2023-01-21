// Leetcode link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
// make vector reverse for alternate times and push back the vector

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        auto* dump = new vector<int>;
        queue<TreeNode*>q;
        bool tr = true;
        if(root == NULL)
        {
            return ans;
        }
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            if(temp == NULL )
            {   
                q.pop();
                if(!tr)(reverse((*dump).begin(),(*dump).end()));
                ans.push_back(*dump);
                (*dump).clear();
                if(!q.empty())
                {
                    q.push(NULL);
                    
                }
                tr = !tr;
                
            }
            else 
            {   q.pop();
                
                  if(temp->left)  q.push(temp->left);
                  if(temp->right) q.push(temp->right);
                  (*dump).push_back(temp->val);
                
            }
        }
        return ans;
    }
};