class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minlength(n,1e9);
        int l = 0, r =0;
        long long sum = 0;
        int ans = 1e9;
        int best = 1e9;
        while(r<n){
            sum += arr[r];
            while(sum>target){
                sum -= arr[l];
                l++;
            }
            if(sum==target){
                int len = r-l+1;
                if(l>0 && minlength[l-1]!=1e9){
                    ans = min(ans,len+minlength[l-1]);
                }
                best = min(best,len);
            }
            minlength[r] = best;
            r++;
        }
        return ans==1e9?-1:ans;
    }
};