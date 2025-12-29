class Solution {
public:
    #define ll long long
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long x = (ll)min(need1,need2);
        long long total =0;
        if(x*(ll)costBoth < (x*(ll)cost1 + x*(ll)cost2)){
            total += x*(ll)costBoth;
            if(need1>need2){
                total += (need1-need2)*(ll)(min(costBoth,cost1));
            }
            else if(need2>need1){
                total += (need2-need1)*(ll)(min(costBoth,cost2));
            }
        }
        else{
            total += (need1)*(ll)(min(costBoth,cost1));
            total += (need2)*(ll)(min(costBoth,cost2));
        }
        return total;
    }
};