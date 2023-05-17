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
    int pairSum(ListNode* head) {
        int count=0;
        ListNode* tmp=head;
        while(tmp)
        {
            count++;
            tmp=tmp->next;
        }
        vector<int>table;
        int cur=0;
        while(head&&cur<count/2)
        {
            cur++;
            table.push_back(head->val);
            head=head->next;
        }
        while(head)
        {
            table[cur-1]+=head->val;cur--;
            head=head->next;
        }
        sort(table.begin(),table.end());
        return table[count/2-1];
    }
};
