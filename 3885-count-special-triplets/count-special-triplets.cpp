class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        map<long long,long long
        > pre,after;
        for(int i=0;i<nums.size();i++){
            after[nums[i]]++;
        }
        long long count = 0;
        for(int i=0;i<nums.size();i++){
            after[nums[i]]--;
            int x = nums[i]*2;
            if(pre.find(x)!=pre.end() && after.find(x)!=after.end() && pre[x]>0 && after[x]>0){
                count += pre[x]*after[x];
            }
            pre[nums[i]]++;
        }
        long long mod = 1e9 + 7;
        return count%mod;
    }
};