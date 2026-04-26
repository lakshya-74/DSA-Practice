class Solution {
public:
    long long total;
    bool check(string s , int mid,vector<int>& order,int k){
        long long count = 0;
        for(int i=0;i<=mid;i++) s[order[i]] = '*';
        long long len = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*') len++;
            else{
                count += 1LL* (len)*(len+1)/2;
                len = 0;
            }
        }
        count += 1LL * len*(len+1)/2;
        return (total - count>=k);
    }
    int minTime(string s, vector<int>& order, int k) {
        int n = order.size();
        int lo = 0;
        int hi = n-1;
        int ans = -1;
        total = 1LL * n*(n+1)/2;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(s,mid,order,k)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};