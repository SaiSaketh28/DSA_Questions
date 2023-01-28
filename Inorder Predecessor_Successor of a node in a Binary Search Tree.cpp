void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    Node* temp = root;
    Node* temp1 = root;
    while(temp != NULL)
    {
        if(temp->key<=key)
        {
            temp = temp->right;
        }
        else
        {
            suc = temp;
            temp = temp->left;
        }
    }
    while(temp1 != NULL)
    {
        if(temp1->key>=key)
        {
            temp1 = temp1->left;
        }
        else
        {
            pre = temp1;
            temp1 = temp1->right;
        }
    }
}