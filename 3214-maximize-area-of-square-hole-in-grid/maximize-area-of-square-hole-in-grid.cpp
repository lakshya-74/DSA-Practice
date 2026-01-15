class Solution {
public:
    #define pp pair<int,int>
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        vector<pp> v1,v2;
        for(int i=0;i<hBars.size();i++){
            int initial = hBars[i];
            int end = hBars[i];
            while(i<hBars.size()-1 && hBars[i+1]==hBars[i]+1){
                i++;
                end = hBars[i];
            }
            v1.push_back({initial,end});
        }
        for(int i=0;i<vBars.size();i++){
            int initial = vBars[i];
            int end = vBars[i];
            while(i<vBars.size()-1 && vBars[i+1]==vBars[i]+1){
                i++;
                end = vBars[i];
            }
            v2.push_back({initial,end});
        }
        int square_len = 0;
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                int x = min(v1[i].second-v1[i].first+2,v2[j].second-v2[j].first+2);
                square_len = max(square_len,x);
            }
        }
        return square_len*square_len;
    }
};