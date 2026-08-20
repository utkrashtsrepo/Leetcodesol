class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,1e9);
        dist[src]=0;
        for(int i=0;i<k+1;i++){
        vector<int> tmp=dist;
            
            for(int j=0;j<flights.size();j++){
                int s=flights[j][0];
                int d=flights[j][1];
                int wt=flights[j][2];

                if(dist[s]!=1e9 && tmp[d]>dist[s]+wt ){
                    tmp[d]=dist[s]+wt;
                }
            }
            dist=tmp;
        }
        return dist[dst]==1e9 ?-1:dist[dst];
    }
};