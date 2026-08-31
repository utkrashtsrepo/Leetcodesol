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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode *> st;
        ListNode *curr=head;

        while(curr->next!=nullptr){
            if(st.empty()){
                st.push(curr);
            }
            if(curr->next->val <= st.top()->val){
                st.push(curr->next);
            }
            else{
                while(!st.empty() && !(curr->next->val <= st.top()->val)){
                    st.pop();
                }
                st.push(curr->next);
            }
            curr=curr->next;
        }
        ListNode *nex=nullptr;
        while(!st.empty()){
            ListNode* cur=st.top();
            st.pop();
            cur->next=nex;
            nex=cur;

        }
        return nex;
    }
};