class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()==1) return false;
        map<int,int> mpp;
        for(int i=0;i<deck.size();i++){
            mpp[deck[i]]++;
        }
        int a = 0;
        for(auto x:mpp){
            a = gcd(a,x.second);
        }
        if(a>1) return true;
        return false;
    }
};