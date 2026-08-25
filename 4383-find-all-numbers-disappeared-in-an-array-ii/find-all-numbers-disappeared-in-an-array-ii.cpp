class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        set<int> st;
        for(int i=0;i<n;i++) st.insert(nums[i]);
        int i = lower;
        vector<vector<int>> ans;
        while(i<=upper){
            vector<int> v;
            if(!st.count(i)){
                v.push_back(i);
                v.push_back(i);
                i++;
            }
            while(i<=upper && !st.count(i)){
                int last = v.back();
                if(i>=last){
                    v.pop_back();
                    v.push_back(i);
                }
                i++;
            }
            if(v.size()) ans.push_back(v);
            i++;
        }
        return ans;
    }
};