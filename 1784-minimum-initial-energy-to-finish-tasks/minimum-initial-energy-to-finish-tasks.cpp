class Solution {
public:
    #define ll long long
    bool check(int mid , vector<vector<int>>& v){
        for(int i =v.size()-1;i>=0;i--){
            if(mid<v[i][1]) return false;
            mid -= v[i][0];
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(),tasks.end(),[](vector<int>&a , vector<int>&b){
            if(a[1]-a[0] == b[1]-b[0]) return a[0]<b[0];
            return a[1]-a[0] < b[1]-b[0];
        });
        ll lo = 1;
        ll hi = 1e17;
        int ans= lo;
        while(lo<=hi){
            ll mid = lo + (hi-lo)/2;
            if(check(mid,tasks)){
                ans = mid;
                hi = mid-1;
            } 
            else lo = mid+1;
        }
        return ans;
    }
};