class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans;
        for(int i=1;i<1000;i++){
            if(mp.find(i*k)==mp.end()){
            ans=i*k;
            break;
            }
        }
        return ans;
    }
};