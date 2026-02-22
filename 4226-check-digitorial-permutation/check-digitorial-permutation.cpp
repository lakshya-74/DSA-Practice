class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int sum = 0;
        int x = n;
        vector<int> v = {1,1,2,6,24,120,720,5040,40320,362880};
        map<int,int> mpp;
        while(x>0){
            sum += v[x%10];
            mpp[x%10]++;
            x = x/10;
        }
        while(sum>0){
            if(!mpp.count(sum%10)) return false;
            mpp[sum%10]--;
            if(mpp[sum%10]==0) mpp.erase(sum%10);
            sum = sum/10;
        }
        return mpp.empty();
    }
};