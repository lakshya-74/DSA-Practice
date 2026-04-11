class Solution {
public:
    #define pp pair<int,int>
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<pp> v(n);
        for(int i=0;i<n;i++){
            v[i] = {nums[i],i};
        }
        sort(v.begin(),v.end());
        int i = 0;
        int ans = 1e8;
        while(i<n-2){
            pp x = v[i];
            pp y = v[i+1];
            pp z = v[i+2];
            if(x.first==y.first && y.first==z.first){
                int l = y.second - x.second;
                int m = z.second - x.second;
                int n = z.second - y.second;
                ans = min(ans,l+m+n);
            }
            i++;
        }
        return ans==1e8?-1:ans;
    }
};