class Solution {
public:
    bool check(int mid , vector<int>& arr, int t){
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum += min(mid,arr[i]);
        }
        return sum>=t;
    }
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        int mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx,arr[i]);
        }
        int lo = 0;
        int hi = mx;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            bool x = check(mid,arr,target);
            if(x){
                hi = mid-1;
            }
            else lo = mid+1;
        }
        int sum1 =0 , sum2 = 0;
        for(int i=0;i<n;i++){
            sum1 += min(lo,arr[i]);
            sum2 += min(lo-1,arr[i]);
        }
        return abs(sum1-target)<abs(sum2-target)?lo:lo-1;
    }
};