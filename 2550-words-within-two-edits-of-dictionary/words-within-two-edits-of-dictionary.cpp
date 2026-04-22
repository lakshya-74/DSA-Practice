class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string> ans;
        int m = d.size();
        int n = q.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count =0;
                for(int k=0;k<q[i].size();k++){
                    if(q[i][k]!=d[j][k]) count++;
                    if(count>2) break;
                }
                if(count<=2){
                    ans.push_back(q[i]);
                    break;
                }
            }
        }
        return ans;
    }
};