class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        vector<int> check(s.begin(),s.end());
        for(int ele : check){
            int x = 0;
            while(ele>0){
                x *= 10;
                x += ele%10;
                ele /= 10;
            }
            s.insert(x);
        }
        return s.size();
    }
};