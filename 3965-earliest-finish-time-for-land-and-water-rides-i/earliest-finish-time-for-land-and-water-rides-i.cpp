class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        int n = lst.size();
        int m = wst.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            int total = lst[i] + ld[i];
            for(int j=0;j<m;j++){
                int x = max(0,wst[j]-total);
                x += wd[j];
                ans = min(ans,total+x);
            }
        }   
        for(int i=0;i<m;i++){
            int total = wst[i] + wd[i];
            for(int j=0;j<n;j++){
                int x = max(0,lst[j]-total);
                x += ld[j];
                ans = min(ans,total+x);
            }
        }   
        return ans;
    }
};