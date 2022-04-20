#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;
// 给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列
// 如果是，返回 true ；否则，返回 false 。

// 输入：s1 = "ab" s2 = "eidbaooo"
// 输出：true
// 解释：s2 包含 s1 的排列之一 ("ba")
class Solution {
public:
    bool checkInclusion(string t, string s) {
        unordered_map<char,int> n,w;
        for(char c:t) n[c]++;

        int i=0;
        int j=0;
        int v=0;
        while(j<s.size())
        {
            // 增大窗口
            char c=s[j];
            j++;
            if(n.count(c))
            {
                w[c]++;
                if(w[c]==n[c]) v++;
            }
            // 判断左窗口是否要收缩
            while(j-i>=t.size())
            {
                // 是否找到了合法的子串
                // v可以理解为每一个独立的字母对应了它所应该的数量
                if(v==n.size()&&j-i==t.size()) return true;
                char d=s[i];
                i++;
                bool st = n.count(d);
                if(n.count(d))
                {
                    if(w[d]==n[d]) v--;
                    w[d]--;
                }
            }
        }
        return false;
    }
};

int main()
{
    string a="ab";
    string b="eidbaooo";

    Solution s1;
    printf("%d",s1.checkInclusion(a,b));
}