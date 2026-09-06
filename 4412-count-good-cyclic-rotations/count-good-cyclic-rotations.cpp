class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        vector<long long> pre(2*n+1,0);
        pre[0] = nums[0];
        for(int i=1;i<2*n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
        int ans =0;
        int l=0, r= n-1;
        while(r<2*n-1){
            if(r-l+1==n){
                long long rem = l==0?0:pre[l-1];
                if((pre[r- n/2]-rem)>(pre[r]-pre[r- n/2])) ans++;
            }
            l++;
            r++;
        }
        return ans;
    }
};