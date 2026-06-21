class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // sort(costs.begin(),costs.end());
        // int count =0;
        // for(int i=0;i<costs.size();i++){
        //     if(coins>=costs[i]){
        //         count++;
        //         coins -= costs[i];
        //     }
        //     else break;
        // }
        // return count;

        vector<int> freq(1e5+1,0);
        for(int i=0;i<costs.size();i++){
            freq[costs[i]]++;
        }
        int count =0;
        for(int i=1;i<=1e5;i++){
            if(freq[i]==0) continue;
            int canbuy = min(freq[i],coins/i);
            count += canbuy;
            coins -= canbuy*i;
        }
        return count;
    }
};