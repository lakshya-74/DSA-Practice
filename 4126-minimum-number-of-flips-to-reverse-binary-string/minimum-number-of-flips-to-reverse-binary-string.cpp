class Solution {
public:
    string bin(int n){
        string s = "";
        while(n>0){
            if(n%2) s += '1';
            else s += '0';
            n /= 2;
        }
        return s;
    }
    int minimumFlips(int n) {
        string s1 = bin(n);
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        int count = 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) count++;
        }
        return count;
    }
};