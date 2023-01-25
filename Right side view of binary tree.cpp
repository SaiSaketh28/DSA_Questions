// make use of level ordrr traversal and push back the right most value in every level order traversal
// First mistake I made is going towards traversals 
// Leetcode link:https://leetcode.com/problems/binary-tree-right-side-view/description/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        auto* dump = new vector<int>;
        vector<vector<int>>temp;
        if(root == NULL)
        {
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* remp = q.front();
            q.pop();
            if(remp == NULL)
            {
                if(!q.empty())
                {
                    q.push(NULL);
                }
                temp.push_back(*dump);
                (*dump).clear();
            }
            else
            {
              (*dump).push_back(remp->val);  
              if(remp->right) q.push(remp->right);
            if(remp->left) q.push(remp->left);
            }
            
        }
        for(int i=0;i<temp.size();i++)
        {
            ans.push_back(temp[i][0]);
        }
        return ans;
    }
};