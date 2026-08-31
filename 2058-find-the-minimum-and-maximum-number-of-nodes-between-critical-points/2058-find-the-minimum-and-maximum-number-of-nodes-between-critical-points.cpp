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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mind=INT_MAX;
        int maxd=INT_MIN;
        ListNode *curr=head;
        ListNode *prev=nullptr;
        int cnt=0;
        vector<int> crit;
        while(curr->next!=nullptr && curr->next->next!=nullptr){
            prev=curr;
            curr=curr->next;
            cnt++;
            if(prev->val<curr->val && (curr->next)->val< curr->val ){
                crit.push_back(cnt);
            }
            if(prev->val>curr->val && curr->next->val> curr->val ){
                crit.push_back(cnt);
            }

        }
        if(crit.size()<2){
            return {-1,-1};
        }
        for(int i=0;i<crit.size()-1;i++){
            mind=min(mind,crit[i+1]-crit[i]);
        }
        maxd=crit.back()-crit.front();
        return {mind,maxd};

    }
};