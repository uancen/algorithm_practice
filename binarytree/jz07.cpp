
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

// 输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int,int> m;
    TreeNode* buildTree(vector<int>& p, vector<int>& q) {
        
    }
};

int main()
{

}