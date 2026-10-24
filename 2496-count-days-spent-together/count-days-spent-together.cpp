class Solution {
public:
    int func(string& s){
        int m = (s[0] - '0')*10 + (s[1] - '0');
        int q = (s[3] - '0') * 10 + (s[4] - '0');
        int ans = (275*m)/9 - 2*((m+9)/12) +q-30;
        return ans;
    }
    int countDaysTogether(string a, string b, string c, string d) {
        return max(0,min(func(b),func(d)) - max(func(a),func(c))+1);
    }
};