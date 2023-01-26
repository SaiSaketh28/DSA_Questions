//Ceil in a Binary search tree
// Link: https://bit.ly/3BULqTJ
// Approach:
/*  1. assign a int ceil with -1
    2. check if root val == input , ceil = input*/
    
    int findCeil(Node* root, int input) 
{
    if (root == NULL) return -1;
    int ceil =-1;
    while(root)
    {
        if(root->data == input)
        {
            ceil = root->data;
        }
        if(root->data<input)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
    // Your code here
}