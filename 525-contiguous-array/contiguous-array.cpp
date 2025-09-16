class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mpp;
        int ans = 0;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) sum += -1;
            else sum += 1;
            if(sum==0) ans = max(ans,i+1);
            else{
                if(mpp.find(sum)!=mpp.end()){
                    ans = max(ans,i-mpp[sum]);
                }
                else mpp[sum] = i;
            }
        }
        return ans;
    }
};