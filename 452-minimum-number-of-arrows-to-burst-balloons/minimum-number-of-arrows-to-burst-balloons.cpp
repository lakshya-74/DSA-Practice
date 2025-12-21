class Solution {
public:
    static bool cmp(vector<int>& p1 ,vector<int>& p2){
        return p1[1]<p2[1];
    }
    int findMinArrowShots(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();
        int count =0;
        int pre = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=pre) count++;
            else pre = intervals[i][1];
        }
        return intervals.size()-count;
    }
};