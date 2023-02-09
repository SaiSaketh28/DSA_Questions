// My Approach:
void path(Node* root,vector<Node*>&temp,vector<int>&dump,vector<vector<int>>&ans)
{   
    if(root == NULL)
    {
        return;
    }
    
    if(root->left == NULL && root->right == NULL)
    {   temp.push_back(root);
        for(int i=0;i<temp.size();i++)
        {
            dump.push_back(temp[i]->data);
        }
        ans.push_back(dump);
        dump.clear();
        temp.pop_back();
        return;
    }
    else
    {
        temp.push_back(root);
        path(root->left,temp,dump,ans);
        path(root->right,temp,dump,ans);
        temp.pop_back();
        root = temp.back();
    }
}
vector<vector<int>> Paths(Node* root)
{
    vector<Node*>temp;
    vector<vector<int>>ans;
    vector<int>dump;
    if(root == NULL)
    {
        return ans;
    }
    path(root,temp,dump,ans);
    return ans;
}

// Optimised Solution
bool getPath(node * root, vector < int > & arr, int x) {
  // if root is NULL
  // there is no path
  if (!root)
    return false;

  // push the node's value in 'arr'
  arr.push_back(root -> data);

  // if it is the required node
  // return true
  if (root -> data == x)
    return true;

  // else check whether the required node lies
  // in the left subtree or right subtree of
  // the current node
  if (getPath(root -> left, arr, x) ||
    getPath(root -> right, arr, x))
    return true;

  // required node does not lie either in the
  // left or right subtree of the current node
  // Thus, remove current node's value from
  // 'arr'and then return false   
  arr.pop_back();
  return false;
}