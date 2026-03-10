class Solution {
public:
    int maxConsecutiveAnswers(string nums, int k) {
        int n = nums.size();
        int l = 0 , r = 0 , ans = 0 ;
        int t = 0 , f =0;
        while(r<n){
            if(nums[r]=='T') t++;
            else f++;
            int changes = r-l+1 - (max(t,f));
            if(changes>k){
                if(nums[l]=='T') t--;
                else f--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};