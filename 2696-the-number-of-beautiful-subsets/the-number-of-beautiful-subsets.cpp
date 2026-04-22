class Solution {
public:
    int rec(int idx , int k , vector<int>& nums,vector<int>& v){
        if(idx<0) return 0;
        int a = 0;
        v.push_back(nums[idx]);
        bool flag = true;
        for(int i=0;i<v.size();i++){
            if(abs(nums[idx]-v[i])==k){
                flag = false;
                break;
            }
        }
        if(flag) a = 1 + rec(idx-1,k,nums,v);
        v.pop_back();
        int b = rec(idx-1,k,nums,v);
        return a+b;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v;
        return rec(n-1,k,nums,v);
    }
};