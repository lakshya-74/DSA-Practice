class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> mpp;
        unordered_map<int,int> indegree,outdegree;
        for(auto x:pairs){
            mpp[x[0]].push_back(x[1]);
            indegree[x[1]]++;
            outdegree[x[0]]++;
        }
        int start = pairs[0][0];
        for(auto x:outdegree){
            if(x.second == indegree[x.first]+1){
                start = x.first;
                break;
            }
        }
        stack<int> s;
        vector<int> v;
        s.push(start);
        while(!s.empty()){
            auto curr = s.top();
            if(mpp[curr].size()==0){
                v.push_back(curr);
                s.pop();
            }
            else{
                auto x = mpp[curr].back();
                mpp[curr].pop_back();
                s.push(x);
            }
        }
        reverse(v.begin(),v.end());
        vector<vector<int>> ans;
        for(int i=0;i<v.size()-1;i++){
            ans.push_back({v[i],v[i+1]});
        }
        return ans;
    }
};