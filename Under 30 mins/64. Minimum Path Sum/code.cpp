class Solution {
public:
int dp[201][201];
    int minPathSum(vector<vector<int>>& ob) {
        memset(dp,-1,sizeof(dp));
        
        dfs(ob.size()-1,ob[0].size()-1,ob);

        // for(int i=0;i<ob.size();i++)
        // {for(int j=0;j<ob[0].size();j++)
        // cout<<dp[i][j]<<" ";
        // cout<<endl;}
        return dp[ob.size()-1][ob[0].size()-1];
    }
       int dfs(int i,int j,vector<vector<int>>& ob){
        if(i<0 || j<0) return -1;

        // if(i==0 && j==0 ) return ob[i][j];
        
        
        if(dp[i][j]==-1){
            int x = dfs(i-1,j,ob) ;
            int y = dfs(i,j-1,ob);

            if(x==-1 && y==-1)
            dp[i][j]=ob[i][j];
            else if(x==-1)
            dp[i][j]=ob[i][j]+y;
            else if(y==-1) dp[i][j]=ob[i][j]+x;
            else dp[i][j]=ob[i][j]+min(x,y);
            // cout<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<dp[i][j]<<endl;
        }
        return dp[i][j];
    }
};
