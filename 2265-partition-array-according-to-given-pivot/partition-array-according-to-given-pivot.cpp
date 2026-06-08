class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int count =0;
        vector<int> less;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                less.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                count++;
            }
        }
        vector<int> ans(n);
        int k =0;
        for(int i=0;i<less.size();i++){
            ans[k++] = less[i];
        }
        while(count--){
            ans[k++] = pivot;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>pivot) ans[k++] = nums[i];
        }
        return ans;
    }
};