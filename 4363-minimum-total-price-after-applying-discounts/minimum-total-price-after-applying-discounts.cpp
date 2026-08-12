class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& dis) {
        sort(prices.begin(),prices.end());
        sort(dis.begin(),dis.end());
        int j = dis.size()-1;
        double ans = 0.0;
        for(int i=prices.size()-1;i>=0;i--){
            if(j>=0){
                ans += (prices[i]*(100-dis[j]))/100.0;
                j--;
            }
            else ans += prices[i];
        }
        return ans;
    }
};