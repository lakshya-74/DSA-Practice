class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string,vector<string>> mpp;
        for(int i=0;i<n;i++){
            string s1 = tickets[i][0];
            string s2 = tickets[i][1];
            mpp[s1].push_back(s2);
        }
        for(auto &[x,y]:mpp){
            sort(y.rbegin(),y.rend());
        }
        stack<string> st;
        vector<string> ans;
        st.push("JFK");
        while(!st.empty()){
            string s = st.top();
            cout<<s<<" ";
            if(mpp[s].size()==0){
                ans.push_back(s);
                st.pop();
            }
            else{
                string u = mpp[s].back();
                mpp[s].pop_back();
                st.push(u);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};