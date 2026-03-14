class Solution {
public:
    vector<char> v = {'a','b','c'};
    string ans;
    void rec(int idx , int n , int& k,char c,string & s){
        if(idx>=n){
            k--;
            if(k==0){
                ans = s;
            }
            return;
        }
        for(int i=0;i<3;i++){
            if(v[i]!=c){ 
                s += v[i];
                rec(idx+1,n,k,v[i],s);
                s.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        string s = "";
        rec(0,n,k,'z',s);
        return ans;
    }
};