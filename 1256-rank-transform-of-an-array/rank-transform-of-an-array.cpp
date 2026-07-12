class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return {};
        vector<int> v = arr;
        sort(v.begin(),v.end());
        vector<int> temp;
        for(int i=0;i<n-1;i++){
            if(v[i]!=v[i+1]) temp.push_back(v[i]);
        }
        temp.push_back(v[n-1]);
        map<int,int> mpp;
        for(int i=0;i<temp.size();i++){
            mpp[temp[i]] = i+1;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = mpp[arr[i]];
        }
        return ans;
    }
};