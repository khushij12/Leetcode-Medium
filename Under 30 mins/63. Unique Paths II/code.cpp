class Solution {
public:
    int dp[101][101];
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        memset(dp,-1,sizeof(dp));
        
        return dfs(ob.size()-1,ob[0].size()-1,ob);
    }
    
    int dfs(int i,int j,vector<vector<int>>& ob){
        if(i<0 || j<0) return 0;
        if(ob[i][j]) return 0;
        if(i==0 && j==0 ) return 1;
        
        
        if(dp[i][j]==-1){
                dp[i][j]=dfs(i-1,j,ob) + dfs(i,j-1,ob);
        }
        return dp[i][j];
    }
};
