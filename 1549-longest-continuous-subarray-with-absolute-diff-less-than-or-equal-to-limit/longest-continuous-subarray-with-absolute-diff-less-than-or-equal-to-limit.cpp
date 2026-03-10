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
                if(mx.top().second > mn.top().second){
                    int x = mn.top().second +1;
                    while(mn.top().second<x){
                        mn.pop();
                    }
                    l = x;
                }
                else{
                    int x = mx.top().second +1;
                    while(mx.top().second<x){
                        mx.pop();
                    }
                    l = x;
                }
            }
            if((mx.top().first - mn.top().first)<=limit) ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};