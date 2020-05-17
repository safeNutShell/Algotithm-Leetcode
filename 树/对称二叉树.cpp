/*
给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
    1
   / \
  2   2
   \   \
   3    3
*/

bool SubSymmetric(TreeNode* l, TreeNode* r){
    if(!l && !r)
        return true;
    if(!l || !r)
        return false;
    if(l->val==r->val)
        return SubSymmetric(l->left, r->right) && SubSymmetric(l->right, r->left);
    return false;
}

bool isSymmetric(TreeNode* root) {
    if(root==NULL) return true;
    else return SubSymmetric(root->left, root->right);
}

/*
尝试了利用层次遍历实现迭代算法，但是对空结点不好处理，所以还是改用递归。
递归的关键是找到入口点，下copy一个分析过程
1.怎么判断一棵树是不是对称二叉树？ 答案：如果所给根节点，为空，那么是对称。如果不为空的话，当他的左子树与右子树对称时，他对称
2.那么怎么知道左子树与右子树对不对称呢？在这我直接叫为左树和右树 答案：如果左树的左孩子与右树的右孩子对称，左树的右孩子与右树的左孩子对称，那么这个左树和右树就对称。
函数A（左树，右树）功能是返回是否对称
def 函数A（左树，右树）： 左树节点值等于右树节点值 且 函数A（左树的左子树，右树的右子树），函数A（左树的右子树，右树的左子树）均为真 才返回真
*/
