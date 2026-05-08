class Solution {
public:
    vector<bool> prime;
    void sieve(int n) {
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            mpp[nums[i]].push_back(i);
        }
        prime.assign(mx+1,true);
        prime[0] = false;
        prime[1] = false;
        sieve(mx);
        vector<int> visited(n,0);
        set<int> st; // used for already visited primes
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        int jumps = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front();
                q.pop();
                if(i==n-1) return jumps;
                if(i-1>=0 && !visited[i-1]){
                    q.push(i-1);
                    visited[i-1] = 1;
                }
                if(i+1<n && !visited[i+1]){
                    q.push(i+1);
                    visited[i+1] = 1;
                }
                if(prime[nums[i]] && !st.count(nums[i])){
                    for(int mul=nums[i];mul<=mx;mul+=nums[i]){
                        for(auto x:mpp[mul]){
                            if(!visited[x]){
                                q.push(x);
                                visited[x] = 1;
                            }
                        }
                    }
                    st.insert(nums[i]);
                }
            }
            jumps++;
        }
        return jumps;
    }
};