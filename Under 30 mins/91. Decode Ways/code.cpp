class Solution {
public:
    
    int numDecodings(string s) {
        vector<int> dp(101,-1);
 
        return dfs(s.length()-1,s,dp);
        
    }

    int dfs(int i,string s,vector<int> &dp){
        if(i<0) return 1;
        
        if(dp[i]==-1){
             dp[i]=0;
            if(i-1>=0 && ((s[i-1]=='2' && s[i]<='6') || s[i-1]=='1'))
                dp[i] = dfs(i-2,s,dp);
            
            if(s[i]!='0')
            dp[i]+=dfs(i-1,s,dp);
        }
        

        return dp[i];
    }
};
