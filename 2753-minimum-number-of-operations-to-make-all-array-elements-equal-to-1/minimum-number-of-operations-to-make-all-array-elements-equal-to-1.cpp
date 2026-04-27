class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) count++;
        }
        if(count>0) return n-count;
        int ans = INT_MAX;
        for(int i=0;i<n-1;i++){
            int gcd = nums[i];
            for(int j=i+1;j<n;j++){
                gcd = __gcd(gcd,nums[j]);
                if(gcd==1){
                    ans = min(ans,j-i);
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans + n-1;
    }
};