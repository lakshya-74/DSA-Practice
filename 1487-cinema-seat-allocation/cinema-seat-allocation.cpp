class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int ans = 2*n;
        sort(rs.begin(),rs.end());
        int sz = rs.size();
        for(int i=0;i<sz;i++){
            bool flag1 = true;
            bool flag2 = true;
            bool flag3 = true;
            int r = rs[i][0];
            int c = rs[i][1];
            while(i<sz && rs[i][0]==r){
                if(rs[i][1]>=2 && rs[i][1]<=5){
                    flag1 = false;
                    if(rs[i][1]>=4 && rs[i][1]<=5) flag2= false;
                }
                else if(rs[i][1]>=6 && rs[i][1]<=9){
                    flag3 = false;
                    if(rs[i][1]>=6 && rs[i][1]<=7) flag2 = false;
                }
                i++;
            }
            i--;
            if(!flag1 && !flag2 && !flag3) ans -= 2;
            else if(!flag1 || !flag2 || !flag3) ans--;
        }
        return ans;
    }
};