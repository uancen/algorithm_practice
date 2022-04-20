// https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
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

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode *root, int tar)
    {
        recur(root,tar);
        return res;
    }
    void recur(TreeNode *root, int tar)
    {
        if(root==nullptr) return;
        path.push_back(root->val);
        int sum = 0;
        for(int a : path) sum+=a;
        if(sum==tar&&root->left==nullptr&&root->right==nullptr) res.push_back(path);
        recur(root->left,tar);
        recur(root->right,tar);
        path.pop_back();
        return;
    }
};

int main()
{
    // leetcode已经ac
}