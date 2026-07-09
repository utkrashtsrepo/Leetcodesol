class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> ind(numCourses);
        vector<int> adj[numCourses];

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ind[prerequisites[i][0]]++;
        }
        for(int i=0;i<ind.size();i++){
            if(ind[i]==0)q.push(i);

        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(int i=0;i<adj[node].size();i++){
                ind[adj[node][i]]--;
                if(ind[adj[node][i]]==0)q.push(adj[node][i]);
            }
        }
        if(topo.size()==numCourses){
            return topo;
        }
        return {};
    }
};