class Solution {
public:
    #define ll long long
    long long gcdSum(vector<int>& nums) {
        int mx = 0;
        int n = nums.size();
        vector<int> pre(n);
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            pre[i] = __gcd(mx,nums[i]);
        }
        sort(pre.begin(),pre.end());
        ll sum = 0;
        int i = 0 , j = n-1;
        while(i<j){
            sum += __gcd(pre[i++],pre[j--]);
        }
        return sum;
    }
};