class Solution {
public:
    #define ll long long
    int check(int k , vector<int>& x , ll& ansx){
        int x_val;
        for(int i=0;i<k;i++){
            ll curr = 0;
            for(int j=0;j<x.size();j++){
                int diff = abs(x[j]-i);
                curr += min(diff,k-diff);
            }
            if(ansx>curr){
                ansx = curr;
                x_val = i;
            }
        }
        return x_val;
    }
    int func(int k , vector<int>& x , ll& ansx , int val){
        int x_val;
        for(int i=0;i<k;i++){
            ll curr = 0;
            if(i==val) continue;
            for(int j=0;j<x.size();j++){
                int diff = abs(x[j]-i);
                curr += min(diff,k-diff);
            }
            if(ansx>curr){
                ansx = curr;
                x_val = i;
            }
        }
        return x_val;
    }
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> x , y;
        for(int i=0;i<n;i++){
            if(i&1){
                y.push_back(nums[i]%k);
            }
            else x.push_back(nums[i]%k);
        }
        ll ansx = 1e18;
        int x_val = check(k,x,ansx);
        ll ansy = 1e18;
        int y_val = func(k,y,ansy,x_val);
        int ans = ansx + ansy;

        ansy = 1e18;
        y_val = check(k,y,ansy);
        ansx = 1e18;
        x_val = func(k,x,ansx,y_val);
        ans = min(ans,(int)(ansx + ansy));
        return ans;
    
        

        
    }
};