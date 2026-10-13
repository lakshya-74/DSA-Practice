class Solution {
public:
    #define ll long long
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.rbegin(),nums.rend());
        int i =0 , j = n-1;
        ll ans = 0;
        while(i<j){
            ans += nums[i]*nums[i];
            ans -= nums[j]*nums[j];
            i++;
            j--;
        }
        if(i==j) ans += nums[i]*nums[j];
        return ans;
    }
};