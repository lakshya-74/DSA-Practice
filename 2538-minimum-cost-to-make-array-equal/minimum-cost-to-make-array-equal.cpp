class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        int lo=INT_MAX,hi=INT_MIN,mid;
        for(int i=0;i<n;i++){
            lo=min(lo,nums[i]);
            hi=max(hi,nums[i]);
        }
        long long totalCost=LLONG_MAX;
        long long midCost=0,midCost1=0;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            midCost=0;midCost1=0;
            for(int i=0;i<n;i++){
                midCost+=(abs(mid-nums[i])*1LL*cost[i]);
                midCost1+=(abs(mid+1-nums[i])*1LL*cost[i]);
            }
            totalCost=min({totalCost,midCost,midCost1});
            if(midCost1<midCost) lo=mid+1;
            else hi=mid-1;
        }
        return totalCost;
    }
};