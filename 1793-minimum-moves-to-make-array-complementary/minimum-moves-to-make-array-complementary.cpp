class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> v(2*limit +2,0);
        for(int i=0;i<n/2;i++){
            int a= nums[i];
            int b = nums[n-i-1];
            int l = min(a,b) + 1;
            int r = max(a,b) + limit;
            v[2] += 2;
            v[2*limit+1] -= 2;

            v[l]--;
            v[r+1]++;

            v[a+b]--;
            v[a+b+1]++;
        }
        int ans = INT_MAX;
        for(int i=2;i<=2*limit;i++){
            v[i] += v[i-1];
            ans = min(ans,v[i]);
        }
        return ans;
    }
};