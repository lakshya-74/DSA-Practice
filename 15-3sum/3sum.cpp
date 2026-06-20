class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        // better one

        // set<vector<int>> st;
        // for(int i=0;i<n;i++){
        //     unordered_set<int> st1;
        //     for(int j=i+1;j<n;j++){
        //         int num = -nums[i] - nums[j];
        //         if(st1.find(num)!=st1.end()){
        //             vector<int> temp = {nums[i],nums[j],num};
        //             sort(temp.begin(),temp.end());
        //             st.insert(temp);
        //         }
        //         else{
        //             st1.insert(nums[j]);
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin(),st.end());
        // return ans;

        // optimal

        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            while(i>0 && i<n && nums[i]==nums[i-1]) i++;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[k]==nums[k+1]) k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                }
            }
        }
        return ans;
    }
};