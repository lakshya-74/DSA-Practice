class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mpp;
        for(int i=0;i<arr1.size();i++){
            mpp[arr1[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<mpp[arr2[i]];j++) ans.push_back(arr2[i]);
            mpp.erase(arr2[i]);
        }
        for(auto x:mpp){
            for(int i=0;i<x.second;i++) ans.push_back(x.first);
        }
        return ans;
    }
};