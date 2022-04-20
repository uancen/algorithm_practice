// https://leetcode-cn.com/problems/minimum-window-substring/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;
// 给你一个字符串 s 、一个字符串 t 
// 返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""

// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"

// 输入：s = "a", t = "a"
// 输出："a"

// 首先寻找可行解。其次优化可行解，最后得到最优解
// 因为是乘法+正整数的限制条件：默认有一个“顺序”

// 套用模板的四个问题
// 1、当移动right扩大窗口，即加入字符时，应该更新哪些数据？
// 2、什么条件下，窗口应该暂停扩大，开始移动left缩小窗口？
// 3、当移动left缩小窗口，即移出字符时，应该更新哪些数据？
// 4、我们要的结果应该在扩大窗口时还是缩小窗口时进行更新？
class Solution {
public:
    string minWindow(string s, string t) {
        // 用哈希表记录窗口中的字符（w）和需要的字符（n）
        unordered_map<char,int> n,w;
        for(char c : t) n[c]++;

        int i=0;
        int j=0;
        int v=0;

        int l=0;int len=INT_MAX;
        while(j<s.size())
        {
            // 增大窗口
            char c = s[j];
            j++;
            if(n.count(c))
            {
                w[c]++;
                if(w[c]==n[c]) v++;
            }
            while(v==n.size())
            {
                if(j-i<len)
                {
                    l=i;
                    len=j-i;
                }
                char d=s[i];
                i++;
                if(n.count(d))
                {
                    if(w[d]==n[d]) v--;
                    w[d]--;
                }

            }
        }
        return len == INT_MAX ?
        "" : s.substr(l,len);
    }
};

int main()
{

}