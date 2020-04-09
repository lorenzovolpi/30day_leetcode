#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0, cnt = 0;
        ListNode *cur = head;
        while(cur != NULL) {
            ++len;
            cur = cur->next;
        }

        cur = head;
        while(cur != NULL) {
            ++cnt;
            if(cnt == (len/2) + 1) return cur;
            else cur = cur->next;
        }

        return NULL;
    }
};