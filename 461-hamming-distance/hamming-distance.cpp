class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        int a = x^y; // no. of set bits is the different bits bwtween two numbers
        while(a){ // count of set bits
            a = a&(a-1);
            ans++;
        }
        return ans;
    }
};