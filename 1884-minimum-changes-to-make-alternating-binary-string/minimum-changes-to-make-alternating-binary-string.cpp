class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int count1 = 0;
        char ch = '0';
        for(int i=0;i<n;i++){
            if(s[i]!=ch) count1++;
            ch = (ch=='0')?'1':'0';
        }
        ch = '1';
        int count2 = 0;
        for(int i=0;i<n;i++){
            if(s[i]!=ch) count2++;
            ch = (ch=='0')?'1':'0';
        }
        return min(count1,count2);
    }
};