class Solution {
public:
    bool check(int m , vector<int>& price , int k){
        int n = price.size();
        int pre= price[0];
        k--;
        for(int i=1;i<n;i++){
            if(price[i]-pre>=m){
                k--;
                pre = price[i];
                if(k<=0) return true;
            }
        }
        return k<=0;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n = price.size();
        int lo = 0;
        int hi = price[n-1] - price[0];
        int ans =0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,price,k)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
};