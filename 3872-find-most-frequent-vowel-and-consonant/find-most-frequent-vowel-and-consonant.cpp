class Solution {
public:
    bool isvowel(char c){
        return (c=='a' || c=='e'|| c=='i' || c=='o' || c=='u');
    }
    int maxFreqSum(string s) {
        map<char,int> m1;
        map<char,int> m2;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])) m1[s[i]]++;
            else m2[s[i]]++;
        }
        int a1 = 0 , a2 = 0;
        for(auto x:m1) a1 = max(a1,x.second);
        for(auto x:m2) a2 = max(a2,x.second);
        return a1+a2;
    }
};