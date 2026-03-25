class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
        map<int,int> mpp;
        mpp[0] = -1;
        for(int i=0;i<n;i++){
            if(mpp.find(pre[i]%k)!=mpp.end()){
                if(i-mpp[pre[i]%k]>=2) return true;
            }
            else mpp[pre[i]%k] = i;
        }
        return false;
    }
};