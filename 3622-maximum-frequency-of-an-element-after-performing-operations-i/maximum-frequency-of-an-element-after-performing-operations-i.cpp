class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int no) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end()) + k;
        vector<int> diff(mx+2,0);
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            int l = max(nums[i]-k,0);
            int r = min(nums[i]+k,mx);
            diff[l]++;
            diff[r+1]--;
        }
        int ans =0;
        for(int i=0;i<=mx;i++){
            diff[i] += i>0?diff[i-1]:0;
            int conversions = diff[i] - mpp[i];
            int x = min(conversions,no);
            ans = max(ans,mpp[i]+x);
        }
        return ans;
    }
};