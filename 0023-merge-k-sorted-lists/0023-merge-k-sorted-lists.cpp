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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode *>,vector<pair<int,ListNode *>>,greater<pair<int,ListNode *>>>pq;
        for(auto it:lists){
            if(it!=NULL)
            pq.push({it->val,it});
        }
        ListNode *dummyNode =new ListNode(-1);
        ListNode *curr=dummyNode;
        while(!pq.empty()){
            ListNode *node=pq.top().second;
            pq.pop();
            curr->next=node;
            curr=curr->next;
            if(node->next!=NULL) pq.push({node->next->val,node->next});
        }

        return dummyNode->next;
        
    }
};