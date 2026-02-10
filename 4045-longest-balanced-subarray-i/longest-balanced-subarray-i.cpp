class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        set<int> st1,  st2;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(nums[j]&1) st2.insert(nums[j]);
                else st1.insert(nums[j]);
                if(st1.size()==st2.size()) ans = max(ans,j-i+1);
            }
            st1.clear();
            st2.clear();
        }
        return ans;
    }
};