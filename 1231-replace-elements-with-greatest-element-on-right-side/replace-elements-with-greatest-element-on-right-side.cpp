class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans = arr;
        int n = arr.size();
        int mx = arr[n-1];
        ans[n-1] = -1;
        for(int i=n-2;i>=0;i--){
            ans[i] = mx;
            mx = max(mx,arr[i]);
        }
        return ans;
    }
};