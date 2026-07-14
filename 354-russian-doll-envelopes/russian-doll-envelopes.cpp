class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(),e.end(),[](vector<int> a , vector<int> b){
            if(a[0]==b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int n = e.size();
        vector<int> ans;
        ans.push_back(e[0][1]);
        for(int i=1;i<n;i++){
            if(e[i][1]>ans.back()) ans.push_back(e[i][1]);
            else{
                int lo = 0;
                int hi = ans.size() - 1;
                while(lo<=hi){
                    int mid = lo + (hi-lo)/2;
                    if(ans[mid]>=e[i][1]) hi = mid-1;
                    else lo = mid+1;
                }
                if(lo<ans.size()) ans[lo] = e[i][1];
            }
        }
        return ans.size();
    }
};