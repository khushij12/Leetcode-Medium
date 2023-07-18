class Solution {
public:
    
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=word1.length();i>=0;i--){
            for(int j=word2.length();j>=0;j--){
                if(i==word1.length() || j==word2.length()){
                    dp[i][j] = word1.length()-i + word2.length() -j;
                }else if(word1[i]==word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }else {
                    dp[i][j] = 1 + min(dp[i+1][j],min(dp[i][j+1], dp[i+1][j+1]));
                }
            }
        }
        return dp[0][0];
    }
};
