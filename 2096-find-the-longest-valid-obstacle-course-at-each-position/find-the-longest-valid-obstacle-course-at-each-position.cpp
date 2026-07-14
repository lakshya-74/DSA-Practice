class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& o) {
        int n = o.size();
        vector<int> ans(n);
        vector<int> v;
        v.push_back(o[0]);
        ans[0] = 1;
        for(int i=1;i<n;i++){
            if(o[i]>=v.back()){
                v.push_back(o[i]);
                ans[i] = v.size();
            }
            else{
                int lo = 0;
                int hi = v.size()-1;
                while(lo<=hi){
                    int mid = lo + (hi-lo)/2;
                    if(v[mid]<=o[i]) lo = mid+1;
                    else hi = mid-1;
                }
                v[lo] = o[i];
                if(lo+1<v.size() && v[lo+1]>=v[lo]) ans[i] = lo+1;
                else ans[i] = v.size();
            }
        }
        return ans;
    }
};