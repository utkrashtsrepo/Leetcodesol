class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0;int r=0;
        unordered_map<int,int> mp;
        int res=INT_MIN;
        for(r;r<s.length();r++){
            mp[s[r]]++;
            while(mp[s[r]]>2){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(mp[s[l]]);
                }
                l++;
            }
            
            res=max(res,r-l+1);
        }
    return res;
    }
};