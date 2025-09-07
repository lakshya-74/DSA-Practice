class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1) return {0};
        vector<int> ans(n);
        for(int i=0;i<n-1;i+=2){
            ans[i] = -(i+1);
            ans[i+1] = (i+1);
        }
        if(n&1) ans[n-1] = 0;
        return ans;
    }
};