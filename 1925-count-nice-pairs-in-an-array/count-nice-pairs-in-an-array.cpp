class Solution {
public:
    int rev(int n){
        int r = 0;
        while(n>0){
            r = r*10 + n%10;
            n /= 10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i] -= rev(nums[i]);
        }
        map<int,int> mpp;
        int count =0;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])!=mpp.end()){
                count = count%1000000007;
                count += mpp[nums[i]];
            }
            mpp[nums[i]]++;
        }
        return count%1000000007;
    }
};