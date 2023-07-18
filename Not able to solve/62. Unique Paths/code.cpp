class Solution {
public:
    int dp[101][101];
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        
        return dfs(m-1,n-1,m,n);
    }
    
    int dfs(int i,int j,int m,int n){
        if(i==0 || j==0) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        dp[i][j] = dfs(i-1,j,m,n) + dfs(i,j-1,m,n);
        return dp[i][j];
    }
};
