class Solution {
public:
    int reverse(int n){
        int x =0;
        while(n>0){
            x *= 10;
            x += n%10;
            n /= 10;
        }
        return x;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            int rev = reverse(nums[i]);
            s.insert(rev);
        }
        return s.size();
    }
};