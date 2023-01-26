// Link: https://bit.ly/3Asftl0
/*
Approach: 1. First we make queue and push root with 0;
2. Now we assign line numbers to all vertical imaginary lines and insert them in queue by updating their line number
3. Now we insert line number and data value of q.front() into a map
4. map sorts line numbers in ascending order
5. we traversal the map and push back data values into vector
*/
//code:
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*,int>>q;
        map<int,int>map;
        vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }
        q.push({root,0});
        while(!q.empty())
        {   auto temp = q.front();
            q.pop();
            Node* node = temp.first;
            int line = temp.second;
            map[line] = node->data;
            if(node->left) q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
        }
        auto it = map.begin();
        while(it != map.end())
        {
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};
