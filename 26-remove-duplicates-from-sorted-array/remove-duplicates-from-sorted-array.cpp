class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int ans =0;
        int l = 0 , r = 1;
        int k =0;
        while(l<n){
            while(r<n && nums[l]==nums[r]) r++;
            ans++;
            nums[k++] = nums[l];
            l = r;
            r++;
        }
        return ans;
    }
};