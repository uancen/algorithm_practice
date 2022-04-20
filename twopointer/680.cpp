#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

// 输入: s = "abca"
// 输出: true
// 解释: 你可以删除c字符。

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int l=0,r=n-1;
        while(l<r)
        {
            if(s[l]==s[r]) {l++;r--;continue;}
            else return (check(l,r-1,s)||check(l+1,r,s));
        }
        return true;
    }
    bool check(int l,int r,string &s)
    {
        while(l<r) {if(s[l]!=s[r]) return false; l++; r--;}
        return true;
    }
};

int main()
{
    string s("deeee");
    // for(char c:s) printf("%c",c);
    Solution s1;
    bool b = s1.validPalindrome(s);
    printf("%d",b);

}