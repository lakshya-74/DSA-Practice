class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> ans(m,-1);
        for(int i=0;i<m;i++){
            ans[i] = m-i;
            int ni = startPos[0] , nj = startPos[1];
            for(int j=i;j<m;j++){
                if(s[j]=='R'){
                    nj++;
                }
                else if(s[j]=='L'){
                    nj--;
                }
                else if(s[j]=='U') ni--;
                else ni++;
                if(ni<0 || ni>=n || nj<0 || nj>=n){
                    ans[i] = j-i;
                    break;
                }
            }
        }
        return ans;
    }
};