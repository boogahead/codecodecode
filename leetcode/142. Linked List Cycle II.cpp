/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       set<ListNode*> visited;
       ListNode*tmp = head;
       while(tmp!=NULL)
       {
           if(visited.find(tmp)!=visited.end())return tmp;
           visited.insert(tmp);
           tmp=tmp->next;
       }
       return NULL;
    }
};
