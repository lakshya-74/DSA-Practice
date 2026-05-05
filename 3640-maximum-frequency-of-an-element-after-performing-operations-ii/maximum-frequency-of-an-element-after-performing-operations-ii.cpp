class Solution {
public:
    #define ll long long
    int maxFrequency(vector<int>& nums, int k, int no) {
        ll n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        map<int,int> mpp;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            ll l = max(0,nums[i]-k);
            ll r = min(nums[i] + k,mx);
            freq[nums[i]]++;
            mpp[l]++;
            mpp[r+1]--;
            mpp[nums[i]] += 0;
        }
        int ans =1;
        int currsum = 0;
        for(auto it=mpp.begin();it!=mpp.end();it++){
            int target = it->first;
            it->second += currsum;
            int conversions = it->second - freq[target];
            int x = min(conversions,no);
            ans = max(ans,freq[target]+x);
            currsum = it->second;
        }
        return ans;
    }
};