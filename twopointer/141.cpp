// https://leetcode-cn.com/problems/linked-list-cycle/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <deque>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public: 
    // 思路：是否存在环即快慢指针是否相遇
    bool hasCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        do
        {
            if(fast->next==nullptr||fast->next->next==nullptr) return false;
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);
        return true;
    }
};


int main()
{

}