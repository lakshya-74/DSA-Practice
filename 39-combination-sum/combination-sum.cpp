class Solution {
public:
    void rec(int idx,int target,int sum,vector<int>& arr,vector<int>& v,vector<vector<int>>& ans){
        if(sum==target){
            ans.push_back(v);
            return;
        }
        if(idx==arr.size() || sum>target){
            return;
        }
        v.push_back(arr[idx]);
        rec(idx,target,sum+arr[idx],arr,v,ans);
        v.pop_back();
        rec(idx+1,target,sum,arr,v,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        rec(0,target,0,arr,v,ans);
        return ans;
    }
};