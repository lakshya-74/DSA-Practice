class Solution {
public:
    vector<int> primes(int n){
        if(n<2) return {};
        vector<bool> check(n+1,true);
        check[0] = check[1] = false;
        for(int i=2;1LL*i*i<=n;i++){
            if(check[i]){
                for(int j=i*i;j<=n;j+=i){
                    check[j] = false;
                }
            }
        }
        vector<int> prime;
        for(int i=2;i<=n;i++){
            if(check[i]) prime.push_back(i);
        }
        return prime;
    }
    void pfac(int n , unordered_map<int,int>& mpp,vector<int>& prime){
        for(int p : prime){
            if(1LL*p*p>n) break;
            if(n%p==0){
                mpp[p]++;
                while(n%p==0){
                    n /=p;
                }
            }
        }
        if(n>1) mpp[n]++;
    }
    void rfac(int n , unordered_map<int,int>& mpp,vector<int>& prime){
        for(int p:prime){
            if(1LL*p*p>n) break;
            if(n%p==0){
                mpp[p]--;
                if(mpp[p]==0) mpp.erase(p);
                while(n%p==0){
                    n /= p;
                }
            }
        }
        if(n>1){
            mpp[n]--;
            if(mpp[n]==0){
                mpp.erase(n);
            }
        }
    }
    int longestSubarray(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> prime = primes(mx);
        unordered_map<int,int> mpp;
        int n = nums.size();
        int l =0 , r = 0;
        int ans =0;
        while(r<n){
            pfac(nums[r],mpp,prime);
            while(mpp.size()>k){
                rfac(nums[l],mpp,prime);
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};