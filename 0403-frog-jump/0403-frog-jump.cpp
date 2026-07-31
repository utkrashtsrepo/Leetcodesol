class Solution {
public:
    bool fun(int i,int n,int k,vector<int> &stones,unordered_map<int,int> &mp,vector<vector<int>> &dp){
        if(i==n-1){
            return true;
        }
        if (dp[i][k] != -1)
            return dp[i][k];

        for(int jump=k-1;jump<=k+1;jump++){
            if(jump<1){
                continue;
            }
            int nextpos=stones[i]+jump;
            if(mp.count(nextpos)){
                int nextind=mp[nextpos];
                if(fun(nextind,n,jump,stones,mp,dp))
                    return dp[i][k]=true; 
            }
        }
        return dp[i][k]=false;
    }
    bool canCross(vector<int>& stones) {
        unordered_map <int,int> mp;
        int n=stones.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        if(stones[1]!=1){
            return false;
        }
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        return fun(1,n,1,stones,mp,dp);
    }
};