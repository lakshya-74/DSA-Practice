class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int thres) {
        int n = arr.size();
        int l=0,r=0;
        long long sum = 0;
        int ans =0;
        while(r<n){
            sum += arr[r];
            if(r-l+1>k){
                sum -= arr[l];
                l++;
            }
            if(r-l+1==k){
                if(sum/k>=thres) ans++;
            }
            r++;
        }
        return ans;
    }
};