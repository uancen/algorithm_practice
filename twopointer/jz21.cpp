// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <deque>
using namespace std;


// 输入：nums = [1,2,3,4]
// 输出：[1,3,2,4] 
// 注：[3,1,2,4] 也是正确的答案之一。
class Solution
{
public:
    // 快慢指针
    vector<int> exchange(vector<int> &nums)
    {
        int i = 0;
        int j = 0;
        while (j < nums.size())
        {
            // 快指针总是要向右找奇数
            if ((nums[j] & 1) == 1)
            {
                swap(nums[i], nums[j]);
                // 慢指针总是停留在最左的一个偶数上
                // 慢指针左侧必然是原来存在/已经交换好的奇数序列
                i++;
            }
            j++;
        }
        return nums;
    }
    // 首尾指针
    vector<int> exchange2(vector<int> &nums)
    {
        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            while(i<j&&(nums[i]%2)==1) i++;
            while(i<j&&(nums[j]%2)==0) j--;
            swap(nums[i],nums[j]);
            i++;j--;
        }
        return nums;
    }
    // 双端队列
    vector<int> exchange3(vector<int> &nums)
    {
        int n=nums.size();
        deque<int> t;
        for(int i:nums)
        {
            if((i%2)==1) t.push_front(i);
            else t.push_back(i);
        }
        for(int i=0;i<n;i++) nums[i]=t[i];
        return nums;
    }
};

int main()
{
    vector<int> a{1,2,3,4,5,6,7,8,9};
    
    Solution s1;
    s1.exchange3(a);
    for(int i:a) printf("%d",i);
}