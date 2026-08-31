class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,int> mpp;
        int n = nums.size();
        mpp[nums[0]]++;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]) mpp[nums[i]]++;
        }
        int ans =0;
        for(auto x:mpp){
            if(x.second==1) ans++;
        }
        return ans;
    }
};