class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int maxnum = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            maxnum = max(maxnum,arr[i]);
        }
        int count = 0;
        while(maxnum>0){
            count++;
            maxnum /= 2;
        }
        vector<int> ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<=count;i++){
            for(int j=0;j<n;j++){
                if(__builtin_popcount(arr[j])==i){
                    ans.push_back(arr[j]);
                }
            }
        }
        return ans;
    }
};