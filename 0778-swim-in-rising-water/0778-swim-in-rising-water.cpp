class Solution {
public:
    bool valid(int n,int m,int r,int c){
        if(r>=0 && r<n && c>=0 && c<m){
            return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=grid[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({dist[0][0],{0,0}});
        vector<int> r={0,0,1,-1};
        vector<int> c={1,-1,0,0};
        while(!pq.empty()){
            int d=pq.top().first;
            int ro=pq.top().second.first;
            int co=pq.top().second.second;
            pq.pop();
            if(d>dist[ro][co]){
                continue;
            }
            for(int i=0;i<4;i++){
                int row=ro+r[i];
                int col=co+c[i];
                if(!valid(n,m,row,col)){
                    continue;
                }
                int newd=max(d,grid[row][col]);
                if(dist[row][col]>newd){
                    dist[row][col]=newd;
                    pq.push({newd,{row,col}});
                }
            }
        }
        return dist[n-1][m-1];

    }
};