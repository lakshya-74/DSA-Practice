class Solution {
public:
    int decres(vector<int> nums){
        int k = nums.size();
        for(int i=0;i<k;i++){
            nums.push_back(nums[i]);
        }
        int sz = 2*k;
        int l = 0 , r = 1;
        int dec = 0;
        while(r<sz){
            if(nums[r]<nums[r-1]) dec++;
            while(r-l+1>k){
                if(nums[l+1]<nums[l]) dec--;
                l++;
            }
            if(r-l+1==k){
                if(dec==k-1) return l;
            }
            r++;
        }
        return 1e8;
    }
    int incres(vector<int> nums){
        int k = nums.size();
        for(int i=0;i<k;i++){
            nums.push_back(nums[i]);
        }
        int sz = 2*k;
        int l = 0 , r = 1;
        int inc = 0;
        while(r<sz){
            if(nums[r]>nums[r-1]) inc++;
            while(r-l+1>k){
                if(nums[l+1]>nums[l]) inc--;
                l++;
            }
            if(r-l+1==k){
                if(inc==k-1) return l;
            }
            r++;
        }
        return 1e8;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool check = true;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                check = false;
                break;
            }
        }
        if(check) return 0;
        int a = incres(nums);
        int b = 1 + decres(nums);
        reverse(nums.begin(),nums.end());
        int c = 1 + incres(nums);
        int d = 2 + decres(nums);
        int ans = min({a,b,c,d});
        return ans>=1e8?-1:ans;
    }
};