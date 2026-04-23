class Solution {
public:
    #define ll long long
    vector<long long> getDistances(vector<int>& nums) {
        int n = nums.size();
        vector<ll> ans(n,0);
        // formula we will get for left side = freq*i - (sum till i)
        map<ll,ll> a,b; // a for freq , b for sum
        for(int i=0;i<n;i++){
            ans[i] += a[nums[i]]*i - (b[nums[i]]);
            a[nums[i]]++;
            b[nums[i]] += i;
        }

        // same for right side formula = (sum till i) - (freq*i);
        a.clear();
        b.clear();
        for(int i=n-1;i>=0;i--){
            ans[i] += (b[nums[i]]) - (a[nums[i]]*i);
            a[nums[i]]++;
            b[nums[i]] += i;
        }
        return ans;
    }
};