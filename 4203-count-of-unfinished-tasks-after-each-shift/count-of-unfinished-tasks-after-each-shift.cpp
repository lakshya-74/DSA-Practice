class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& sh) {
        int sz = tasks.size();
        vector<long long> pre(sz+1,0);
        pre[0] = tasks[0];
        for(int i=1;i<sz;i++){
            pre[i] = tasks[i] + pre[i-1];
        }
        int n = sh.size();
        vector<int> ans(n,0);
        long long curr = 0;
        long long total = pre[sz-1];
        for(int i=0;i<n;i++){
            curr += sh[i];
            if(curr>=total){
                ans[i] = 0;
                curr = 0;
            }
            else{
                int lo = 0 , hi = sz-1;
                while(lo<=hi){
                    int mid = lo + (hi-lo)/2;
                    if(pre[mid]<=curr){
                        lo = mid+1;
                    }
                    else hi = mid-1;
                }
                ans[i] = sz - lo;
            }
        }
        return ans;
    }
};