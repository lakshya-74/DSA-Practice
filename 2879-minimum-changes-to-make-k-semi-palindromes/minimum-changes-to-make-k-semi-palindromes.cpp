class Solution {
public:
    int n;
    string str;
    vector<vector<int>> dp1 , dp2;
    int getcost(int i,int j){
        int len = j-i+1;
        if(dp1[i][j]!=-1) return dp1[i][j];
        int ans = INT_MAX;
        for(int d=1;d<len;d++){
            if(len%d!=0) continue;
            int cost = 0;
            for(int group=0;group<d;group++){
                int l = i + group;
                int r = l + (len/d -1)*d;
                while(l<=r){
                    if(str[l]!=str[r]) cost++;
                    l+=d;
                    r-=d;
                }
            }
            ans = min(ans,cost);
        }
        return dp1[i][j] = ans;
    }
    int solve(int start , int k){
        if(k==0){
            if(start==n) return 0;
            return INT_MAX;
        }
        if(start + 2*k > n) return INT_MAX;
        if(dp2[start][k]!=-1) return dp2[start][k];
        int mincost = INT_MAX;
        for(int end = start+1;end<n;end++){
            int rem = solve(end+1,k-1);
            if(rem>=INT_MAX) continue;
            mincost = min(mincost,getcost(start,end)+rem);
        }
        return dp2[start][k] = mincost;
    }
    int minimumChanges(string s, int k) {
        str = s;
        n = s.size();
        dp1.assign(n+1,vector<int>(n+1,-1));
        dp2.assign(n,vector<int>(k+1,-1));
        return solve(0,k);
    }
};