class Solution {
public:

    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // Har linked list ka first node heap mein daalo
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        // Dummy node
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(!pq.empty()) {

            ListNode* curr = pq.top();
            pq.pop();

            // Current smallest node answer mein lagao
            tail->next = curr;
            tail = curr;

            // Us list ka next node heap mein daalo
            if(curr->next != NULL) {
                pq.push(curr->next);
            }
        }

        return dummy->next;
    }
};