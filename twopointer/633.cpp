#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

// 输入：c = 5
// 输出：true
// 解释：1 * 1 + 2 * 2 = 5

class Solution {
public:
    bool judgeSquareSum(int c) {
        int b = sqrt(c);
        int i=0,j=b;
        while(i<=j)
        {
            int t=c-j*j;
            if(t==i*i) return true;
            else if(t<i*i) j--;
            else i++;
        }
        return false;
    }
};

int main()
{
    int a=5;
    Solution s1;
    printf("%d",s1.judgeSquareSum(a));
}