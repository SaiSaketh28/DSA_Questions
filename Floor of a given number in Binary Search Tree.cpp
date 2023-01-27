// link:https://bit.ly/3TSbXXE
// Time complexity : O(H) -- height of the required node
int floor(Node* root, int x) {
    // Code here
    if(root == NULL)
    {
        return -1;
    }
    int flor = -1;
    while(root)
    {
        if(x == root->data)
        {
            flor = x;
            break;
        }
        if(x<root->data)
        {
            root = root->left;
        }
        else
        {
            flor = root->data;
            root = root->right;
        }
    }
    return flor;
}