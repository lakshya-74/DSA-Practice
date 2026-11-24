class Solution {
public:
    #define ll long long 
    ll lcm(ll a, ll b){
        return (a/__gcd(a,b))*b;
    }
    int maxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            ll p = 1 , g = 0 , l = 1;
            for(int j=i;j<n;j++){
                p = p*nums[j];
                if(p>2600) break;
                g = __gcd(g,(ll)nums[j]);
                l = lcm(l,(ll)nums[j]);
                if(p== l*g){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};