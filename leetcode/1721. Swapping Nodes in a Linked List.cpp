/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int counter=0;
        ListNode* front=nullptr;
        ListNode* end=nullptr;
        ListNode* cur=head;
        while(cur)
        {
            counter++;
            if(end!=NULL)
            {
                end=end->next;
            }
            if(counter==k)
            {
                front=cur;
                end=head;
            }
            cur=cur->next;
        }
        swap(front->val,end->val);
        return head;
    }
};
