class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mpp;
        int count =0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int mx =0;
        for(auto x: mpp){
            if(x.second>mx){
                mx = x.second;
            }
        }
        for(auto x:mpp){
            if(x.second==mx) count+= x.second;
        }
        return count;
    }
};