class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> check(n+1);
        digits[n-1] += 1;
        int cary = 0;
        for(int i=n-1;i>=0;i--){
            check[i] = (cary+digits[i])%10;
            cary = (cary+digits[i])/10;
        }
        if(cary>0){
            for(int i=n-1;i>=0;i--){
                check[i+1] = check[i];
            }
            check[0] = cary;
        }
        else{
            check.erase(check.begin()+n);
        }
        return check;
    }
};