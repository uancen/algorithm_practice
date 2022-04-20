class Solution {
public:
    void merge(vector<int>& p, int m, vector<int>& q, int n) {
        // a++返回值为a；++a返回值为a+1
        int pos=m--+n---1;
        while(m>=0&&n>=0) p[pos--]=p[m]>q[n]?p[m--]:q[n--];
        while(n>=0) p[pos--]=q[n--];
    }
};