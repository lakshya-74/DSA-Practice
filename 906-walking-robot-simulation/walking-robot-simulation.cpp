class Solution {
public:
    int robotSim(vector<int>& c, vector<vector<int>>& o) {
        int n = c.size();
        int m = o.size();
        set<pair<int,int>> st;
        for(int i=0;i<m;i++){
            st.insert({o[i][0],o[i][1]});
        }
        int dx = 0, dy = 1;
        pair<int,int> curr = {0,0};
        int ans = 0;
        for(int i=0;i<n;i++){
            if(c[i]==-1){
                int temp = dx;
                dx = dy;
                dy = -temp;
            }
            else if(c[i]==-2){
                int temp = dx;
                dx = -dy;
                dy = temp;
            }
            else{
                for(int k=0;k<c[i];k++){
                    int nx = curr.first + dx;
                    int ny = curr.second + dy;
                    if(st.count({nx,ny})) break;
                    curr.first = nx;
                    curr.second = ny;
                    int x = curr.first*curr.first + curr.second*curr.second;
                    ans = max(ans,x);
                }
            }
        }
        return ans;
    }
};