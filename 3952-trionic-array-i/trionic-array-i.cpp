class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        // int mx = INT_MIN;
        // int mn = INT_MAX;
        // for(int i=0;i<n;i++){
        //     mx = max(mx,nums[i]);
        //     mn = min(mn,nums[i]);
        // }
       
        // if(nums[0]==mx) return false;
        // if(nums[n-1]==mn) return false;
        int p=0;
        int q=n-1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[p]) p++;
            else break;
        }
        for(int i=n-2;i>=p;i--){
            if(nums[i]<nums[q]) q--;
            else break; 
        }
        if(p==q || p==0 || q==n-1) return false;
        for(int i=p+1;i<=q;i++){
            if(nums[i]>=nums[i-1]) return false;
        }
        return true;
    }
};