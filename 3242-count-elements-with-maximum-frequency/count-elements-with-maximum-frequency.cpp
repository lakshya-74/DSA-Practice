class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mpp;
        int count =0;
        int mx =0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            mx = max(mx,mpp[nums[i]]);
        }
        for(auto x:mpp){
            if(x.second==mx) count+= x.second;
        }
        return count;
    }
};