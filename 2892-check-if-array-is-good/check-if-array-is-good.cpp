class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return false;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int mx = *max_element(nums.begin(),nums.end());
        if(mpp[mx]!=2) return false;
        for(int i=1;i<mx;i++){
            if(mpp.find(i)==mpp.end()) return false;
            if(mpp[i]>1) return false;
        }
        return true;
    }
};