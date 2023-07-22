class Solution {
public:
    int numTrees(int n) {

        if(n==1) return 1;
        int cnt=0;
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));

        for(int i=1;i<=n;i++)
        dp[i][i] = 1;

        for(int i=1;i<=n;i++){
            int l = dfs(dp, n, 1, i-1);
            int r = dfs(dp, n, i+1, n);

            if(l==0 || r==0)
            cnt+=l+r;
            else
            cnt+=l*r;
        }

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return cnt;
    }

    int dfs(vector<vector<int>> &dp,int n, int st, int end){
        if(st>end) return 0;
        
        if(dp[st][end]!=-1) return dp[st][end];
        int cnt=0;
        for(int i=st;i<=end;i++){
            int l = dfs(dp, n, st, i-1);
            int r = dfs(dp, n, i+1, end);
            
            if(l==0 || r==0)
            cnt+=l+r;
            else
            cnt+=l*r;
            // cout<<i<<" "<<l<<" "<<r<<endl;;
        }
        dp[st][end]=cnt;

        return dp[st][end];
    }
};
