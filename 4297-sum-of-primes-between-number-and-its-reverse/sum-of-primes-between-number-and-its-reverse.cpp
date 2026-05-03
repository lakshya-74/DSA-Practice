class Solution {
public:
    vector<int> seive(int n){
        vector<bool> v(n+1,true);
        for(int p=2;p*p<=n;p++){
            if(v[p]){
                for(int i=p*p;i<=n;i+=p){
                    v[i] = false;
                }
            }
        }
        vector<int> ans;
        for(int i=2;i<=n;i++){
            if(v[i]) ans.push_back(i);
        }
        return ans;
    }
    int sumOfPrimesInRange(int n) {
        int r = 0;
        int x = n;
        while(x>0){
            r = r*10 + x%10;
            x /= 10;
        }
        vector<int> v1 = seive(max(r,n));
        int sum = 0;
        for(int i=0;i<v1.size();i++){
            if(v1[i]>=min(r,n)) sum += v1[i];
        }
        return sum;
    }
};