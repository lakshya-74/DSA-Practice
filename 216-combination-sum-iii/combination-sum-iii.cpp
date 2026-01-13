class Solution {
public:
    void rec(int idx,int target,int k,vector<int>& arr,vector<int>& v ,vector<vector<int>>& ans){
        if(k==0){
            if(target==0){
                ans.push_back(v);
            }
            return;
        }
        if(idx>=arr.size()){
            return;
        }
        for(int i=idx;i<arr.size();i++){
            if(arr[i]>target) break;
            v.push_back(arr[i]);
            rec(i+1,target-arr[i],k-1,arr,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr(9);
        for(int i=0;i<9;i++){
            arr[i] = i+1;
        }
        vector<vector<int>> ans;
        vector<int> v;
        rec(0,n,k,arr,v,ans);
        return ans;
    }
};