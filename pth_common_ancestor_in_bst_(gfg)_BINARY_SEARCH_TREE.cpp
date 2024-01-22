int commonAncestor(int x,int y,NODE* root,int p,int& count)
{
    if(!root) return -1;
    int left = -1, right = -1, ancestor = -1;
    
    if(root->data > x && root->data > y) left = commonAncestor(x,y,root->left,p,count);
    if(root->data < x && root->data < y) right = commonAncestor(x,y,root->right,p,count);
    
    count++;
    if(count == p) ancestor = root->data;
    return max(ancestor,max(left,right));
}

int pthCommonAncestor(int x,int y,NODE *root,int p,vector<int> &vec){
    int count = 0;
    return commonAncestor(x,y,root,p,count);
}