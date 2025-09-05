class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> mpp;
        for(int i=0;i<deck.size();i++){
            mpp[deck[i]]++;
        }
        int a = 0;
        for(auto x:mpp){
            a = gcd(a,x.second);
        }
        return a>1;
    }
};