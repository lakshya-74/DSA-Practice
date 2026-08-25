class Solution {
public:
    bool isPalindromic(string s) {
        string str = "";
        for(int i=0;i<s.size();i++){
            int x = (int)s[i];
            string y = "";
            for(int j=7;j>=0;j--){
                y += ((x>>j)&1)?'1':'0';
            }
            cout<<y<<" ";
            str += y;
        }
        int i = 0;
        int j = str.size()-1;
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};