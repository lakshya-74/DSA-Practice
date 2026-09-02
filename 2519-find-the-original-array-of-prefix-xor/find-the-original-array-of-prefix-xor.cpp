class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n);
        ans[0] = pref[0];
        int xr = pref[0];
        for(int i=1;i<n;i++){
            ans[i] = (xr^pref[i]);
            xr ^= ans[i];
        }
        return ans;
    }
};