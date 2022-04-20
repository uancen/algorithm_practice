#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// in:1,0,2
// out:2+1+2=5
class Solution {
public:
    int candy(vector<int>& p) {
        int n=p.size();
        vector<int> q(n,1);

        for(int i=0;i<=n-2;i++)
        {
            if(p[i]>p[i+1]) q[i]++;
        }
        for(int i=n-1;i>=1;i--)
        {
            if(p[i]>p[i-1]) q[i]=max(q[i],q[i-1]+1);
        }
        return accumulate(q.begin(),q.end(),0);
    }
};

int main()
{
    vector<int> ratings{1,0,2};
    Solution s1;
    printf("%d",s1.candy(ratings));
}