class Solution {
public:
    long long check(int speed , vector<int>& arr){
        long long ans = 0;
        for(int i=0;i<arr.size();i++){
            ans += (arr[i]+(long long)speed-1)/(long long)speed;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int hi = piles[0];
        for(int i=0;i<n;i++){
            hi = max(hi,piles[i]);
        }
        int lo = 1;
        int ans;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,piles)<=h){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid +1;
        }
        return ans;
    }
};