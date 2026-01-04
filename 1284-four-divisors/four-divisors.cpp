class Solution {
public:
    set<int> divisors(int n){
        set<int> st;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                st.insert(i);
                st.insert(n/i);
            }
        }
        return st;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++){
            set<int> st = divisors(nums[i]);
            if(st.size()==4){
                for (int x : st) {
                    sum += x;
                }
            }
        }
        return sum;
    }
};