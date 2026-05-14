class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]); 
    }
    void Union(int a,int b){
        a = find(a);
        b = find(b);
        if(parent[a]!=parent[b]){
            parent[b] = a;
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        parent.resize(mx+1);
        for(int i=0;i<parent.size();i++){
            parent[i] = i;
        }
        for(int i=0;i<n;i++){
            for(int k=2;k<=sqrt(nums[i]);k++){
                if(nums[i]%k==0){
                    Union(nums[i],k);
                    Union(nums[i],nums[i]/k);
                }
            }
        }
        int ans = 0;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            int p = find(nums[i]);
            mpp[p]++;
            ans = max(ans,mpp[p]);
        }
        return ans;
    }
};