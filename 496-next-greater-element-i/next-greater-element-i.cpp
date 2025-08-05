class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        vector<int> nge(n,-1);
        st.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && st.top()<=nums2[i]) st.pop();
            if(st.size()) nge[i] = st.top();
            st.push(nums2[i]);
        }
        int m = nums1.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    ans[i] = nge[j];
                    break;
                }
            }
        }
        return ans;
    }
};