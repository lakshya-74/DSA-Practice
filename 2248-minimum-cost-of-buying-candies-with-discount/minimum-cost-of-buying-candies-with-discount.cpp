class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.rbegin(),cost.rend());
        int ans= 0;
        int i;
        for(i=0;i<n-2;i+=3){
            ans += (cost[i]+cost[i+1]);
        }
        while(i<n){
            ans += cost[i];
            i++;
        }
        return ans;
    }
};