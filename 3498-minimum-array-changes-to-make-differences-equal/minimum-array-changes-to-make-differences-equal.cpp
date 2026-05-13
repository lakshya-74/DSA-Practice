class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> v(k+2,0);
        for(int i=0;i<n/2;i++){
            int a = nums[i];
            int b = nums[n-i-1];
            int l=0;
            int r = max({a,b,k-a,k-b});
            v[0] += 2;
            v[k+1] -= 2;

            v[l]--;
            v[r+1]++;

            v[abs(a-b)]--;
            v[abs(a-b)+1]++;
        }
        int ans = INT_MAX;
        for(int i=0;i<=k;i++){
            if(i>0) v[i] += v[i-1];
            ans = min(ans,v[i]);
        }
        return ans;
    }
};