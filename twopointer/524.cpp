#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

// "aewfafwafjlwajflwajflwafj"
// ["apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"]
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n=s.size();
 
        // string res("");
        sort(dictionary.begin(), 
            dictionary.end(), 
            [&](string &a, string &b) 
            {
                if(a.size() == b.size()) return a < b;
                return a.size() > b.size();
            }
        );

        for(string p:dictionary)
        {
            int i=0,j=0;
            int m=p.size();
            while(i<n&&j<m)
            {
                if(s[i]==p[j]) {i++;j++;continue;}
                else {i++;}  
            }
            if(j==m) return p;
            // if(j==m&&p.size()>res.size()) res=p;
            // if(j==m&&p.size()==res.size()&&p<res) res=p;
        }
        return "";
    }
};

int main()
{
    string s("aewfafwafjlwajflwajflwafj");
    vector<string> p{"apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"};
    Solution s1;
    string res=s1.findLongestWord(s,p);
    for(char c:res) printf("%c",c);
}