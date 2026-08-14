class Solution {
public:
    bool check(int grp , vector<int>& nums){
        int curr = 0;
        int pre = 0;
        for(int i=0;i<nums.size();i++){
            if(curr<=pre){
                curr++;
            }
            else{
                pre = curr;
                curr = 1;
                grp--;
                if(grp<=0) return true;
            }
        }
        if(curr>pre) grp--;
        return grp<=0;
    }
    int maximumGroups(vector<int>& grades) {
        int lo = 0;
        int hi = grades.size();
        sort(grades.begin(),grades.end());
        int ans = 0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,grades)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
};