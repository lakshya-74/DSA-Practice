class Solution {
public:
    void rec(int idx,int target,vector<int> v ,vector<vector<int>>& ans,vector<int>& arr){
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            v.push_back(arr[i]);
            rec(i+1,target-arr[i],v,ans,arr);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(arr.begin(),arr.end());
        rec(0,target,v,ans,arr);
        return ans;
    }
};