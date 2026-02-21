class Solution {
public:
    int count(int n){
        int x = 0;
        while(n>0){
            if(n&1) x++;
            n = n>>1;
        }
        return x;
    }
    int countPrimeSetBits(int left, int right) {
        vector<int> v = {2,3,5,7,11,13,17,19};
        int ans =0;
        for(int i=left;i<=right;i++){
            int x = count(i);
            for(int j=0;j<v.size();j++){
                if(x==v[j]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};