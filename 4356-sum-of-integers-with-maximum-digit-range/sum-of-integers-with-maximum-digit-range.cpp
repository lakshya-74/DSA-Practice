class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int x = nums[i];
            int mn = INT_MAX;
            int mx = INT_MIN;
            while(x>0){
                int a = x%10;
                mn = min(mn,a);
                mx = max(mx,a);
                x = x/10;
            }
            ans = max(ans,mx-mn);
        }
        int sum =0;
        for(int i=0;i<n;i++){
            int x = nums[i];
            int mn = INT_MAX;
            int mx = INT_MIN;
            while(x>0){
                int a = x%10;
                mn = min(mn,a);
                mx = max(mx,a);
                x = x/10;
            }
            if(ans==mx-mn) sum += nums[i];
        }
        return sum;
    }
};