class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int countz = 0;
        for(int i=0;i<n;i++) if(nums[i]==0) countz++;
        int ans =0;
        int j = n-1;
        while(countz){
            if(nums[j]!=0){
                ans++;
            }
            j--;
            countz--;
        }
        return ans;
    }
};