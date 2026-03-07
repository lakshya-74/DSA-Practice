class Solution {
public:
    int check(vector<int>& nums , int goal){
        if(goal<0) return 0;
        int l =0 , r= 0 , ans = 0;
        int n = nums.size();
        int sum =0;
        while(r<n){
            sum += nums[r];
            while(sum>goal){
                sum -= nums[l];
                l++;
            }
            if(sum<=goal){
                ans += (r-l+1); // add length of the curr window take 101 it can generate 3 subarrays with  sum <=goal
            }
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // map<int,int> mpp;
        // int sum = 0;
        // int count =0;
        // for(int i=0;i<nums.size();i++){
        //     sum += nums[i];
        //     if(sum==k) count++;
        //     if(mpp.find(sum-k)!=mpp.end()){
        //         count += mpp[sum-k];
        //     }
        //     mpp[sum]++;
        // }
        // return count;

        // -----------------------
        // two pointer 
        // if we directly calculating the sum==goal 
        // we are struct on some point where we can't decide we have to move l or r
        // so do -->
        // sum<=goal - sum<=(goal-1)
        return check(nums,goal) - check(nums,goal-1);
    }
};