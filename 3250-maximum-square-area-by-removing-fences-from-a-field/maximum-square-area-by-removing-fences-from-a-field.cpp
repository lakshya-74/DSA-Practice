class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& a, vector<int>& b) {
        long long mod = 1e9 + 7;
        a.push_back(1);
        a.push_back(m);
        b.push_back(1);
        b.push_back(n);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        set<int> st;
        bool flag = false;
        for(int i=0;i<a.size()-1;i++){
            for(int j=i+1;j<a.size();j++){
                st.insert(a[j]-a[i]);
            }
        }
        long long side = 1;
        for(int i=0;i<b.size()-1;i++){
            for(int j=i+1;j<b.size();j++){
                if(st.find(b[j]-b[i])!=st.end()){
                    flag = true;
                    side = max(side,(long long)(b[j]-b[i]));
                }
            }
        }
        if(flag==false) return -1;
        return (side*side)%mod;
    }
};