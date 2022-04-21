#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
// 原地删除

// 输入：nums = [1,1,2]
// 输出：2, nums = [1,2,_]
// 输入：nums = [0,0,1,1,1,2,2,3,3,4]
// 输出：5, nums = [0,1,2,3,4]
class Solution {
public:
    int removeDuplicates(vector<int>& q) {
        int i=0;
        int j=1;
        int n=q.size();
        while(j<n)
        {
            if(q[i]!=q[j])
            {
                // 只要保证不重复的前k项是正确的即可
                // 思路就是碰到不重复的就往前拿，而前面的重复数字其实略过即可
                // 总会被后面不重复数字替换、或者直接不计数在最终res中
                q[i+1]=q[j];
                i++;
            }
            j++;
        }
        return i+1;
    }
};

int main()
{
    vector<int> a{0,0,1,1,1,2,2,3,3,4};
    Solution s1;
    int res=s1.removeDuplicates(a);
    printf("%d\n",res);
    for(int i:a) printf("%d",i);
}