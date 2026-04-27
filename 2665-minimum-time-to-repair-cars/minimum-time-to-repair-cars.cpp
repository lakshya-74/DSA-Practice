class Solution {
public:
    #define ll long long
    bool check(ll mid ,vector<int>& ranks, int cars){
        int count =0;
        for(int i=0;i<ranks.size();i++){
            ll x = mid/ranks[i];
            count += sqrt(x);
            if(count>=cars) return true;
        }
        return count>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        sort(ranks.begin(),ranks.end());
        ll lo = 1;
        ll hi = 1e15;
        ll ans = hi;
        while(lo<=hi){
            ll mid = lo + (hi-lo)/2;
            if(check(mid,ranks,cars)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};