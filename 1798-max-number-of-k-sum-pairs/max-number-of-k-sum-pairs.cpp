class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mpp;
        int count =0;
        for(int i=0;i<nums.size();i++){
            if(mpp[k-nums[i]]>0){
                mpp[k-nums[i]]--;
                count++;
            }
            else{
                mpp[nums[i]]++;
            }
        }
        return count;
    }
};