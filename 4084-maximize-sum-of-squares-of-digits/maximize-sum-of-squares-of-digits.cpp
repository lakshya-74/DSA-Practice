class Solution {
public:
    #define ll long long 
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if(sum>9*num) return "";
        while(num--){
            int x = min(sum,9);
            ans += to_string(x);
            sum -= x;
        }
        return ans;
    }
};