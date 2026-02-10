class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans =0;
        map<char,int> mpp;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                int val = mpp[s[j]];
                bool flag = true;
                for(auto x:mpp){
                    if(x.second!=val){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    ans = max(ans,j-i+1);
                }
            }
            mpp.clear();
        }
        return ans;
    }
};