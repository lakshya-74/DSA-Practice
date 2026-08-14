class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<double>> v;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double a = arr[i]/(arr[j]*1.0);
                v.push_back({a,(double)arr[i],(double)arr[j]});
            }
        }
        sort(v.begin(),v.end());
        return {(int)v[k-1][1],(int)v[k-1][2]};
    }
};