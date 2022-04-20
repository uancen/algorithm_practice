// https://leetcode-cn.com/problems/merge-sorted-array/

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

// 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// 输出：[1,2,2,3,5,6]
// 解释：需要合并 [1,2,3] 和 [2,5,6] 。
// 合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。

class Solution {
public:
    void merge(vector<int>& p, int m, vector<int>& q, int n) {
        // a++返回值为a；++a返回值为a+1
        int pos=m--+n---1;
        while(m>=0&&n>=0) p[pos--]=p[m]>q[n]?p[m--]:q[n--];
        while(n>=0) p[pos--]=q[n--];
    }
};

int main()
{
    vector<int> p{1,2,3,0,0,0};
    vector<int> q{2,5,6};
    int m=3,n=3;
    Solution s1;
    s1.merge(p,m,q,n);
    for(int a:p) printf("%d ",a);
}