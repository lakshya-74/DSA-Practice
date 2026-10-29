class Solution {
public:
    #define ll long long
    
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<ll,ll>> v(n);
        ll ans =0;
        for(int i=0;i<n;i++){
            string s = to_string(nums[i]);
            sort(s.rbegin(),s.rend());
            int x = stoi(s);
            int change = x - nums[i];
            v[i] = {change,nums[i]};
            ans += nums[i];
        }
        sort(v.rbegin(),v.rend());
        int i = 0;
        while(k-- && i<n){
            if(v[i].first<=0) break;
            ans += v[i].first;
            i++;
        }
        return ans;
    }
};