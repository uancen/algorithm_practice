// https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
#include<queue>
using namespace std;


// 输入：arr = [3,2,1], k = 2
// 输出：[1,2] 或者 [2,1]

// 输入：arr = [0,1,2,1], k = 1
// 输出：[0]

vector<int> q{5,4,1,3};
class Solution
{
public:
    vector<int> getLeastNum(vector<int> &q, int k)
    {
        vector<int> ans;
        // quick_sort(q,0,q.size()-1);
        // quick_select(q,0,q.size()-1,k);
        // merge_sort(q,0,q.size()-1);
        ans = sortStack(q,k);
        // ans.assign(q.begin(),q.begin()+k);
        return ans;
    }
    void quick_sort(vector<int> &q, int l, int r)
    {
        if(l>=r) return;
        int i=l-1;
        int j=r+1;
        int x=q[(l+r)>>1];
        while(i<j)
        {
            do {i++;} while(q[i]<x);
            do {j--;} while(q[j]>x);
            if(i<j) swap(q[i],q[j]);
        }
        quick_sort(q,l,j);
        quick_sort(q,j+1,r);
    }
    vector<int> quick_select(vector<int> &q, int l, int r, int k)
    {
        vector<int> ans;
        ans.clear();
        if(l>=r) return ans;
        int i=l-1;
        int j=r+1;
        int x=q[(l+r)>>1];
        while(i<j)
        {
            do {i++;} while(q[i]<x);
            do {j--;} while(q[j]>x);
            if(i<j) swap(q[i],q[j]);
        }

        if(i>k) return quick_select(q,l,j,k);
        if(i<k) return quick_select(q,j+1,r,k);
        
        ans.assign(q.begin(),q.begin()+k);
        return ans;
    }
    void merge_sort(vector<int> &q,int l,int r)
    {
        if(l>=r) return;
        int mid=(l+r)>>1;
        merge_sort(q,l,mid);
        merge_sort(q,mid+1,r);

        int k=0,i=l,j=mid+1;
        vector<int> tmp(q.size(),0);
        while(i<=mid&&j<=r)
        {
            if(q[i]<=q[j]) tmp[k++]=q[i++];
            else tmp[k++]=q[j++];
        }
        while(i<=mid) tmp[k++]=q[i++];
        while(j<=r) tmp[k++]=q[j++];
        for(i=l,j=0;i<=r;i++,j++) q[i]=tmp[j];
    }
    vector<int> sortStack(vector<int> &q,int k)
    {
        vector<int> v(k,0);
        if(0==k) return v;

        priority_queue<int> p;
        for(int i=0;i<k;i++) p.push(q[i]);
        for(int i=k;i<q.size();i++)
        {
            if(p.top()>q[i])
            {
                p.pop();
                p.push(q[i]);
            }
        }
        for(int i=0;i<k;i++)
        {
            v[i]=p.top();
            p.pop();
        }
        return v;
    }
};

int main()
{
    vector<int> ans;
    Solution s1;
    int k = 2;
    ans = s1.getLeastNum(q,k);
    for(int i : ans) printf("%d",i);    
}

/*
vector<int> q{3,2,1};
class Solution
{
public:
    void quick_sort(vector<int> &q, int l, int r)
    {
        if(l>=r) return;
        int i=l-1;
        int j=r+1;
        int x=q[l+r>>1];
        while(i<j)
        {
            do {i++;} while(q[i]<x);
            do {j--;} while(q[j]>x);
            if(i<j) swap(q[i],q[j]);
        }
        quick_sort(q,l,j);
        quick_sort(q,j+1,r);
    }
};

int main()
{
    Solution s1;
    s1.quick_sort(q,0,q.size()-1);
    for(int i : q) printf("%d",i);    
}
*/

