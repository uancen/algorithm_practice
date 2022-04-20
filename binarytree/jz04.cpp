// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

// 现有矩阵 matrix 如下：
// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// 给定 target = 5，返回 true。
// 给定 target = 20，返回 false。

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        // 不符合规定的输入
        if(matrix.empty()||matrix.size()==0||matrix[0].size()==0) return false;
        
        int row=matrix.size();
        int col=matrix[0].size();

        int i=0;
        int j=col-1;
        while(i<row&&j>=0)
        {
            int k=matrix[i][j];
            if(k==target) return true;
            else if(k<target) i++;
            else j--;
        }
        return false;
    }
};

int main()
{
    Solution s1;
    
}