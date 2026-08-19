class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n,1e9);
        dist[k-1]=0;
        vector<pair<int,int>> adj[n];
        
        for(int i=0;i<times.size();i++){
            int wt=times[i][2];
            int node=times[i][1]-1;

            pair<int,int> p={node,wt};
            adj[--times[i][0]].push_back(p);

        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({dist[k-1],k-1});
            while(!pq.empty()){
                
                int d=pq.top().first;
                int nod=pq.top().second;
                pq.pop();
                if(dist[nod]<d){
                    continue;
                }
                for(int i=0;i<adj[nod].size();i++){
                    int wt=adj[nod][i].second;
                    int node=adj[nod][i].first;
                    if(d+wt<dist[node]){
                        dist[node]=d+wt;
                    pq.push({dist[node],adj[nod][i].first});
                    }
                }     
            }
            int ans=INT_MIN;
                for(int i=0;i<dist.size();i++){
                    ans=max(ans,dist[i]);
                }
            return ans==1e9 ? -1:ans;
    }
};