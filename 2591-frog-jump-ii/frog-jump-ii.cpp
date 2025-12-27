class Solution {
public:
    int maxJump(vector<int>& stones) {
        int ans = 0;
        int n = stones.size();
        if(n==2) return stones[1]-stones[0];
        for(int i=0;i<n-1;i+=2){
            if(i+2<n) ans = max(ans,abs(stones[i]-stones[i+2]));
        }
        for(int i=1;i<n-1;i+=2){
            if(i+2<n) ans = max(ans,abs(stones[i]-stones[i+2]));
        }
        return ans;

    }
};