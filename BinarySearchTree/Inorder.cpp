#include <iostream>

using namespace std;

typedef int valueType;

struct TreeNode
{
  valueType val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(valueType val, TreeNode* left=0, TreeNode* right=0)
    : val(val), left(left), right(right) {}
};

void inorder(TreeNode* r)
{
  if(!r) {
    return;
  }
  inorder(r->left);
  cout << r->val << endl;
  inorder(r->right);

}

main()
{
  TreeNode* root = new TreeNode(20);
  TreeNode *a = new TreeNode(5);
    TreeNode *b = new TreeNode(40);
    TreeNode *c = new TreeNode(35);
    TreeNode *d = new TreeNode(7);
    root -> right = b;
    root -> left = a;
    b -> left = c;
    a -> right = d;
  //code is hidden
  inorder(root);
}
