/*
给定一个二叉树，原地将它展开为一个单链表。
例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/
void flatten(TreeNode* root) {
    //判断
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) 
        return;
    if(root->left!=NULL && root->right==NULL){
        if(root->left->left==NULL&&root->left->right==NULL){
            root->right=root->left;
            root->left=NULL;
        }
    }
    if(root->left==NULL && root->right!=NULL){
        if(root->right->left==NULL && root->right->right==NULL)
            return;
    }
    flatten(root->left);
    flatten(root->right);
    TreeNode* rightTmp=root->right;
    root->right=root->left;
    root->left=NULL;
    TreeNode* finder=root;
    while(finder->right!=NULL) finder=finder->right;
    finder->right=rightTmp;
}

/*
子树的处理可以递归的进行，所以在进入函数时对一些基本情况做好判断，然后进行左右子树的递归调用。
调用完之后认为左右子树已经规整，此时在根据flat的定义操作左右子树即可。
*/
