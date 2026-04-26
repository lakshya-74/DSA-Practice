class Solution {
public:
    bool check(int idx ,vector<int>& temp , int count,int dir){
        vector<int> nums = temp;
        while(idx>=0 && idx<nums.size() && count>0){
            if(nums[idx]>0){
                nums[idx]--;
                dir *= -1;
                if(nums[idx]==0) count--;
            }
            idx += dir;
        }
        return count==0;
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) count++;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(check(i,nums,count,1)) ans++;
                if(check(i,nums,count,-1)) ans++;
            }
        }
        return ans;
    }
};