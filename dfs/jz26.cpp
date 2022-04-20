// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

// 判断B是不是A的子结构
// 输入：A = [1,2,3], B = [3,1]
// 输出：false

// 输入：A = [3,4,5,1,2], B = [4,1]
// 输出：true

// 思路：先用先序遍历找到A中B的相等节点
// 再以这个节点为根节点开始判断两个树结构是否相等
// 如果结构不相等再继续寻找下一个相等节点

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool inSubStructure(TreeNode* A,TreeNode* B)
    {
        // 题目规定寻找目标不可以是空
        if(B==nullptr) return false;
        return search(A,B);
    }
private:
    bool compare(TreeNode* A,TreeNode* B)
    {
        if(B==nullptr) return true;
        if(A==nullptr) return false;
        return A->val==B->val&&compare(A->left,B->left)&&compare(A->right,B->right);
    }
    
    bool search(TreeNode* A,TreeNode* B)
    {
        // 先序遍历找A节点中是否有和Broot相同的
        if(A==nullptr) return false;
        // 找到相同节点就去检查A和B是否相等
        if(A->val==B->val&&compare(A,B)) return true;
        // 继续先序遍历
        return search(A->left,B)||search(A->right,B);
    }

};

int main()
{
    vector<int> a{1, 2, 3};
    vector<int> b{3, 1};


    TreeNode left1(2);
    TreeNode right1(3);
    TreeNode left2(2);
    TreeNode root1(1,&left1,&right1);
    TreeNode root2(1,&left2,nullptr);

    Solution s1;
    bool st;
    st = s1.inSubStructure(&root1,&root2);
    cout << st;

}