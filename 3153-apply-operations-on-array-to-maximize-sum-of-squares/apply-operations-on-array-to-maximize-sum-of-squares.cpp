class Solution {
public:
    int mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(31,0);
        for(int i=0;i<31;i++){
            for(int j=0;j<nums.size();j++){
                int x = nums[j]>>i;
                if(x&1) count[i]++;
            }
        }
        int ans =0;
        while(k--){
            long long num = 0;
            for(int i=0;i<31;i++){
                if(count[i]){
                    int x = 1<<i;
                    num += x;
                    count[i]--;
                }
            }
            long long y = (num*num)%mod;
            ans = (ans+y)%mod;

        }
        return ans;
    }
};