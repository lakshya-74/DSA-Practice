class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        const int MOD = 1e9 + 7;
        int i=0;
        while(i<n){
            int idx = queries[i][0];
            while(idx<=queries[i][1]){
                nums[idx] = ((long long)nums[idx] * (long long)queries[i][3])% MOD;
                idx += queries[i][2];
            }
            i++;
        }
        int ans =0;
        for(int i=0;i<nums.size();i++){
            ans ^= nums[i];
        }
        return ans;
    }
};