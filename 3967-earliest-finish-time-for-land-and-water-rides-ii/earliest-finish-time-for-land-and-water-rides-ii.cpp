class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n = ls.size();
        int m = ws.size();
        int ans = INT_MAX;
        int min_l = INT_MAX;
        int min_w = INT_MAX;
        for(int i=0;i<n;i++){
            min_l = min(min_l,ls[i]+ld[i]);
        }
        for(int i=0;i<m;i++){
            min_w = min(min_w,ws[i]+wd[i]);
        }
        for(int i=0;i<n;i++){
            ans = min(ans,max(ls[i],min_w)+ld[i]);
        }
        for(int i=0;i<m;i++){
            ans = min(ans,max(ws[i],min_l)+wd[i]);
        }
        return ans;
    }
};