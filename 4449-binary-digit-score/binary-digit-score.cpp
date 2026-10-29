class Solution {
public:
    int count(int n){
        int c = 0;
        while(n){
            n = n& (n-1);
            c++;
        }
        return c;
    }
    int calculateScore(int a, int b) {
        int s1 = count(a);
        int s2 = count(b);
        return s1>=s2?s1*s2:s2/s1;
    }
};