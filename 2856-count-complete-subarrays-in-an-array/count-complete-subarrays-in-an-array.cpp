class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans = 0;
        int dist = st.size();
        st.clear();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                st.insert(nums[j]);
                if(st.size()==dist) ans++;
                else if(st.size()>dist) break;
            }
            st.clear();
        }
        return ans;
    }
};