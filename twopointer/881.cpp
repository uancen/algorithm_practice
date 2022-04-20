#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;
// 给定数组 people 。people[i]表示第 i 个人的体重 ，船的数量不限，每艘船可以承载的最大重量为 limit。
// 每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit。
// 返回承载所有人所需的最小船数 。

// 输入：people = [1,2], limit = 3
// 输出：1
// 解释：1 艘船载 (1, 2)

// 输入：people = [3,2,2,1], limit = 3
// 输出：3
// 解释：3 艘船分别载 (1, 2), (2) 和 (3)
class Solution
{
public:
    int numRescueBoats(vector<int>& people, int limit) {
        quick_sort(people,0,people.size()-1);

        int i=0;
        int j=people.size()-1;
        int res = 0;
        while(j>0)
        {
            if(people[j]>=limit)
            {
                j--;
                res++;
            }
            else break;
        }

        while(i<j)
        {
            if(people[i]+people[j]<=limit) 
            {
                i++;
                j--;
                res++;
            }
            else
            {
                j--;
                res++;
            }
        }
        if(i==j) res++;
        return res;
    }
    void quick_sort(vector<int> &q,int l,int r)
    {
        if(l>=r) return;
        int i=l-1;
        int j=r+1;
        int mid=q[(l+r)>>1];
        while(i<j)
        {
            do{i++;} while(q[i]<mid);
            do{j--;} while(q[j]>mid);
            // 交换前记得再次检查是否i<j
            if(i<j) swap(q[i],q[j]);
        }
        quick_sort(q,l,j);
        quick_sort(q,j+1,r);
    }
};

int main()
{
    vector<int> a{5,1,4,2};

    Solution s1;
    int res = s1.numRescueBoats(a,6);
    printf("%d",res);
}