class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++) mpp[nums[i]]++;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            if(mpp[nums[i]]>=3) mp[nums[i]].push_back(i);
        }
        unordered_set<int> st;
        for(auto x:mp){
            vector<int> v = x.second;
            int curr = v[1] - v[0];
            bool flag = true;
            for(int j=1;j<v.size();j++){
                if(curr != (v[j]-v[j-1])) flag = false;                 
            }
            if(flag) st.insert(x.first);
        }
        return st.size();
    }
};