#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// 给剩余孩子里最小饥饿度的孩子分配最小的能饱腹的饼干
class Solution{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int res=0;
        int n=g.size();
        int m=s.size();
        int i=0;
        int j=0;
        while(i<n&&j<m)
        {
            if(s[j]<g[i]) j++;
            else{
                res++;
                i++;
                j++;
            }
        }
        return res;
    }
};
int main(){
    vector<int> g{1,2,3};
    vector<int> s{1,1};
    Solution s1;
    int res=s1.findContentChildren(g,s);
    printf("%d",res);
    
}
