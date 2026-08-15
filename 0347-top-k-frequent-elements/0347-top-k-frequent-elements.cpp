class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int cnt=0;
        for(auto it:mp){
            int ele=it.first;
            int fre=it.second;
            pair<int,int> p={fre,ele};
            if(cnt<k){
                pq.push(p);
                cnt++;
            }
            else{
                if(p>pq.top()){
                    pq.pop();
                    pq.push(p);
                }
            }
        }
        vector<int> res;
        for(int i=0;i<k;i++){
            int x=pq.top().second;
            res.push_back(x);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};