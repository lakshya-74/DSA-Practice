class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int x = num;
        vector<int> v;
        while(x>0){
            v.push_back(x%10);
            x /= 10;
        }
        reverse(v.begin(),v.end());
        int l = 0 ,r = 0 , ans = 0;
        int n = v.size();
        long long a = pow(10,k);
        int t = 0;
        while(r<n){
            t = t*10 + v[r];
            if(r-l+1>k){
                t = t%a;
                l++;
            }
            if(r-l+1==k){
                if(t!=0 && num%t==0) ans++;
            }
            r++;
        }
        return ans;
    }
};