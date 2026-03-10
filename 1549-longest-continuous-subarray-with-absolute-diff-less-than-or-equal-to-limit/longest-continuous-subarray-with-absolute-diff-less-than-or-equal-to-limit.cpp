class Solution {
public:
    #define pp pair<int,int>
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int l = 0 , r = 0;
        priority_queue<pp> mx;
        priority_queue<pp,vector<pp>,greater<pp>> mn;
        int ans = 0;
        while(r<n){
            mn.push({nums[r],r});
            mx.push({nums[r],r});
            while((mx.top().first - mn.top().first)>limit){
                l = min(mx.top().second,mn.top().second) + 1;
                while(mn.top().second<l){
                    mn.pop();
                }
                while(mx.top().second<l) mx.pop();
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};