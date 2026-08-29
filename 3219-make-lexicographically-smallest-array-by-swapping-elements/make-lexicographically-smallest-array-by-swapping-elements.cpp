class Solution {
public:
    #define pp pair<int,int>
    vector<int> parent; 
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a , int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            parent[b] = a;
        }
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        vector<pp> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = {nums[i],i};
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<n-1;i++){
            if(ans[i+1].first-ans[i].first<=limit) Union(ans[i].second,ans[i+1].second);
        }
        map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[find(i)].push_back(i);
        }
        for(auto x:mpp){
            vector<int> v;
            for(int i=0;i<x.second.size();i++){
                v.push_back(nums[x.second[i]]);
            }
            sort(v.begin(),v.end());
            for(int i=0;i<x.second.size();i++){
                nums[x.second[i]] = v[i];
            }
        }
        return nums;
    }
};