class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        map<long long,long long> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int ans= 1;
        for(int i=0;i<n;i++){
            long long x = nums[i];
            if(x==1){
                int a = mpp[1]%2==0?mpp[1]-1:mpp[1];
                ans = max(ans,a);
                continue;
            }
            int curr = 0;
            while(1){
                if(mpp[x]>1 && mpp.count(pow(x,2))){
                    curr+=2;
                    x = pow(x,2);
                }
                else if(mpp.count(x)){
                    curr++;
                    break;
                }
                else break;
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};