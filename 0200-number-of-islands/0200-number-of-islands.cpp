class Solution {
public:
bool valid(int i,int j,int n,int m){
    if(0<=i && i<n){
        if(0<=j && j<m){
            return true;
        }
    }
    return false;
}

void dfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int i,int j){
    vis[i][j]=1;
    vector<int> d1={0,0,-1,1};
    vector<int> d2={1,-1,0,0};
    for(int k=0;k<d1.size();k++){
        
        if(valid(i+d1[k],j+d2[k],grid.size(),grid[0].size())){
            if(vis[i+d1[k]][j+d2[k]]!=1 && grid[i+d1[k]][j+d2[k]]=='1'){
                dfs(grid,vis,i+d1[k],j+d2[k]);
            }
        }
    }
    return; 
}


    int numIslands(vector<vector<char>>& grid) {
         int count=0;
         int n=grid.size();
         int m=grid[0].size();
         vector<vector<int>> vis(n,vector<int> (m,0)) ;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){

            if(vis[i][j]!=1 & grid[i][j]=='1'){
                dfs(grid,vis,i,j);
                count++;
            }
        }
    }
    return count;
    }
};