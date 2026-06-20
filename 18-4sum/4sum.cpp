class Solution {
public:
    #define ll long long
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            while(i>0 && i<n && nums[i]==nums[i-1]) i++;
            for(int j=i+1;j<n;j++){
                while(j!=i+1 && j<n && nums[j]==nums[j-1]) j++;
                int k = j+1;
                int l = n-1;
                while(k<l){
                    ll sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum>target){
                        l--;
                    }   
                    else{
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};