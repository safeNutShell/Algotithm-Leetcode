/*
根据一棵树的前序遍历与中序遍历构造二叉树。
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

*/

TreeNode* builder(int leftPre, int rightPre, int leftIn, int rightIn, vector<int>& preorder, vector<int>& inorder){
    if(leftPre>rightPre || leftIn>rightIn) return NULL;
    TreeNode* root=new TreeNode(preorder[leftPre]);
    int rootPosition=leftIn;
    while(rootPosition<=rightIn && inorder[rootPosition]!=preorder[leftPre]) rootPosition++;
    int leftLen=rootPosition-leftIn;
    root->left=builder(leftPre+1, leftPre+leftLen, leftIn, rootPosition-1, preorder, inorder);
    root->right=builder(leftPre+leftLen+1, rightPre, rootPosition+1, rightIn, preorder, inorder);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return builder(0, preorder.size()-1, 0, inorder.size()-1, preorder, inorder);
}

/*
构造子树是一个递归的过程，因此要有合适的参数交给递归判断。
数组上的问题用到指针时，最好令指针是一个左右闭区间的两端，这样方便判断。
*/
