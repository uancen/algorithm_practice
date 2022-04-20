// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

// 输入：numbers = [2,7,11,15], target = 9
// 输出：[1,2]
// 解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。

class Solution {
public:
    vector<int> twoSum(vector<int>& p, int target) {
        int n=p.size();
        int l=0,r=n-1;
        int sum;
        while(l<r)
        {
            sum=p[l]+p[r];
            if(sum==target) break;
            else if(sum>target) r--;
            else l++;
        }
        return vector<int>{l+1,r+1};
    }
};

int main()
{
    vector<int> p{2,7,11,15};
    Solution s1;
    vector<int> q = s1.twoSum(p,13);
    for(int a:q) printf("%d ",a);
}