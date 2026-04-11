class Solution {
public:
    #define ll long long
    long long sumDigitDifferences(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int m = 0;
        int x = nums[0];
        while(x>0){
            m++;
            x /= 10;
        }
        vector<vector<int>> v(m);
        for(int i=0;i<n;i++){
            int c = m-1;
            int x = nums[i];
            while(x>0){
                v[c].push_back(x%10);
                x /=10;
                c--;
            }
        }
        ll ans = 0;
        for(int i=0;i<m;i++){
            map<ll,ll> mpp;
            for(int j=0;j<v[i].size();j++){
                mpp[v[i][j]]++;
            }
            ll count = 0;
            for(auto& x:mpp){
                count += x.second*(n-x.second);
            }
            ans += count;
        }
        return ans/2;
    }
};