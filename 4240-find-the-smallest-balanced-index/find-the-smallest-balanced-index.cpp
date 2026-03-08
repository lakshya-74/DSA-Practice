class Solution {
public:
    #define ll long long
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pre(n,0);
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i-1];
        } 
        int ans = -1;
        unsigned ll prod = 1;
        for(int i=n-1;i>=0;i--){
            if(prod==pre[i]){
                ans = i;
            }
            if(prod>pre[i]) break;
            prod *= nums[i]; 
        }
        return ans;
    }
};