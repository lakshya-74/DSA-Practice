class Solution {
public:
    bool isvowel(char c){
        return (c=='a' || c=='e'|| c=='i' || c=='o' || c=='u');
    }
    int maxFreqSum(string s) {
        map<char,int> m1;
        int a1 = 0 , a2 = 0;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                m1[s[i]]++;
                a1 = max(a1,m1[s[i]]);
            }
            else{
                m1[s[i]]++;
                a2 = max(a2,m1[s[i]]);
            }
        }
        return a1+a2;
    }
};