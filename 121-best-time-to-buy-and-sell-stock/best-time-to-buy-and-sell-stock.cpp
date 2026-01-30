class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mn = arr[0];
        int profit = 0;
        for(int i=1;i<arr.size();i++){
            profit = max(profit,arr[i]-mn);
            mn = min(mn,arr[i]);
        }
        return profit;
    }
};