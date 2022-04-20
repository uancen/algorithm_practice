// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/solution/mian-shi-ti-54-er-cha-sou-suo-shu-de-di-k-da-jie-d/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 输入: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// 输出: 4
// 输入: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// 输出: 4

// 思路：二叉搜索树的中序遍历为递增序列 
// 因此，求 “二叉搜索树第 k 大的节点” 可转化为求 “此树的中序遍历倒序的第 k 个节点”
// 中序遍历的倒序 为 “右、根、左” 顺序
class Solution
{
public:
    int res, m;
    int n=0;
    int kthLargest(TreeNode* root, int k) {
        m=k;
        dfs2(root);
        return res;
    }
    void dfs(TreeNode* root)
    {
        if(root==nullptr) return;
        dfs(root->right);
        // 用n记录遍历到节点的个数
        // 选在这里写逻辑：因为这里是中序遍历出数的地方？yp自己的领悟，后面的yp不要信
        n++;
        if(m==n) 
        {
            res=root->val;
            return;
        }
        dfs(root->left);
    }
    // 迭代写法
    void dfs2(TreeNode* root)
    {
        stack<TreeNode*> stk;
        TreeNode* cur=root;
        while(cur!=nullptr||!stk.empty())
        {
            if(cur!=nullptr)
            {
                stk.push(cur);
                cur=cur->right;
            }
            else{
                cur=stk.top();
                stk.pop();
                n++;
                if(m==n)
                {
                    res=cur->val;
                    return;
                }
                cur=cur->left;
            }
        }
    }
};

int main()
{
    TreeNode left1(1);
    TreeNode right1(3);
    TreeNode root1(2,&left1,&right1);

    Solution s1;
    int a = s1.kthLargest(&root1,1);
    printf("%d",a);
}