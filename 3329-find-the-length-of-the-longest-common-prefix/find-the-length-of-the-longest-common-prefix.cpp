class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        set<int> st;
        for(int i=0;i<m;i++){
            string s = to_string(arr2[i]);
            for(int j=0;j<s.size();j++){
                int val = stoi(s.substr(0,j+1));
                st.insert(val);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            string s = to_string(arr1[i]);
            for(int j=0;j<s.size();j++){
                string sub = s.substr(0,j+1);
                int val = stoi(sub);
                if(st.find(val)!=st.end()){
                    ans = max(ans,(int)sub.size());
                }
            }
        }
        return ans;
    }
};