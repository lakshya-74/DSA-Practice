class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto x:st){
            if(st.count(x-1)) continue;
            int curr = 1;
            int y = x+1;
            while(st.count(y)){
                curr++;
                y++;
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};