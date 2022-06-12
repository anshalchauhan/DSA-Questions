int minValue(Node* root) {
    int min1 = -1;
    if(root == NULL) return min1;
    while(root != NULL)
    {
        min1 = root->data;
        root = root->left;
    }
    return min1;
}