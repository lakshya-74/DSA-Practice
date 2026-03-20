class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n,0);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i]; 
        }
        vector<int> ans(n,-1);
        for(int i=k;i<n-k;i++){
            ans[i] = (pre[i+k] - ((i-k-1<0)?0:pre[i-k-1]))/(2*k+1);
        }
        return ans;
    }
};