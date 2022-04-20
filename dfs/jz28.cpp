// https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

//     1
//    / \
//   2   2
//    \   \
//    3    3
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 如果是空树
        if(!root)
            return true;
        else
            return isSymmetric(root->left, root->right);
    }
    // 此函数比较二叉树中位置对称的两个节点
    bool isSymmetric(TreeNode* left, TreeNode* right){
        // 结束条件1：如果对称两个节点都为空，则返回true
        if(!left && !right){
            return true;
        }
        // 结束条件2：如果单独一个节点为空，另一个节点不为空，又或者是对称节点间的val值不等，则返回false
        if(!left || !right || left->val != right->val)
            return false;
        // 该层符合对称二叉树的要求，开始比较下一层
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);      
    }
};