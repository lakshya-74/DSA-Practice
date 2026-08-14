class Solution {
public:
    bool check(int dist , vector<int>& pos , int m){
        int pre = pos[0];
        m--;
        for(int i=1;i<pos.size();i++){
            if(pos[i]-pre>=dist){
                pre = pos[i];
                m--;
                if(m<=0) return true;
            }
        }
        return m<=0;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int lo = 0 , hi = pos[pos.size()-1] - pos[0];
        int ans =0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,pos,m)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
};