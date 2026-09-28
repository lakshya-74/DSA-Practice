class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        int n = g.size();
        vector<vector<bool>> suff(n+1,vector<bool>(3,false));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<g[i].size();j++){
                if(g[i][j]=='M' || suff[i+1][0]) suff[i][0] = true;
                if(g[i][j]=='P' || suff[i+1][1]) suff[i][1] = true;
                if(g[i][j]=='G' || suff[i+1][2]) suff[i][2] = true;
            }
        }
        int m = 0 , p = 0 , ga =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<g[i].size();j++){
                if(g[i][j]=='M') m++;
                else if(g[i][j]=='P') p++;
                else ga++;
            }
            if(suff[i+1][0]) m += t[i];
            if(suff[i+1][1]) p += t[i];
            if(suff[i+1][2]) ga += t[i];
            // cout<<i<<"the iteration"<<endl;
            // cout<<"m->"<<m<<endl;
            // cout<<"p->"<<p<<endl;
            // cout<<"ga->"<<ga<<endl;
        }
        return m + p + ga;
    }
};