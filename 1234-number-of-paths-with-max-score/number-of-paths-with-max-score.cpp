class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<int>> dp(n,vector<int>(n+1,0)), ways(n,vector<int>(n+1,0));
        ways[n-1][n-1] = 1;
        int mod = 1e9+7;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==n-1 && j==n-1) continue;
                if(board[i][j]=='X') continue;
                if(i==0 && j==0){
                    dp[0][0] = max({dp[0][1],dp[1][0],dp[1][1]});
                    if(dp[0][0]==dp[1][0]){
                        ways[i][j] += ways[i+1][j];
                    }
                    if(dp[0][0]==dp[0][1]){
                        ways[i][j] += ways[i][j+1];
                    }
                    if(dp[0][0]==dp[1][1]){
                        ways[i][j] += ways[i+1][j+1];
                    }
                    ways[0][0] %= mod;
                    continue;
                }
                int a = 0 , b = 0 , c = 0;
                if(i+1<n) a = dp[i+1][j];
                if(j+1<n) b = dp[i][j+1];
                if(i+1<n && j+1<n) c = dp[i+1][j+1];
                dp[i][j] = max({a,b,c}) + (board[i][j]-'0');

                int best = max({a,b,c});
                if(i+1<n && a==best){
                    ways[i][j] += ways[i+1][j];
                }
                if(j+1<n && b==best){
                    ways[i][j] += ways[i][j+1];
                }
                if(i+1<n && j+1<n && c==best){
                    ways[i][j] += ways[i+1][j+1];
                }
                ways[i][j] %= mod;
            }
        }
        if(ways[0][0]==0) return {0,0};
        return {dp[0][0],ways[0][0]};
    }
};