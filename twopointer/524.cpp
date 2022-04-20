#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

// "aewfafwafjlwajflwajflwafj"
// ["apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"]
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n=s.size();
 
        string res("");
        for(string p:dictionary)
        {
            int i=0,j=0;
            int m=p.size();
            while(i<n&&j<m)
            {
                if(s[i]==p[j]) {i++;j++;continue;}
                else {i++;}  
            }
            if(j==m&&p.size()>res.size()) res=p;
            if(p.size()==res.size()&&p<res) res=p;
        }
        return res;
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