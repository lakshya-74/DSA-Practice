class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        vector<vector<int>> ans;
        int i=0 , j =0;
        int n = s1.size();
        int m = s2.size();
        while(i<n && j<m){
            int a = s1[i][0];
            int b = s2[j][0];
            if(a<b){
                ans.push_back({a,s1[i][1]+s2[j][1]});
                i++;
            }
            else if(b<a){
                ans.push_back({b,s1[i][1]+s2[j][1]});
                j++;
            }
            else{
                ans.push_back({a,s1[i][1]+s2[j][1]});
                i++;
                j++;
            }
        }
        while(i<n){
            ans.push_back({s1[i][0],s1[i][1]});
            i++;
        }
        while(j<m){
            ans.push_back({s2[j][0],s2[j][1]});
            j++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};