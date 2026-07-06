class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        sort(intervals.begin(),intervals.end(),[](vector<int>& a, vector<int>& b){
            if(a[0]==b[0]) return (a[1]-a[0]) > (b[1]-b[0]);
            return a[0]<b[0];
        });
        int ans = 0;
        int mxnum = -1;
        for(int i=0;i<n;){
            // int j = i+1;
            // while(j<n && intervals[i][1]>=intervals[j][1]){
            //     count++;
            //     j++;
            // }
            // i = j;

            if(intervals[i][1]>mxnum){
                ans++;
                mxnum = intervals[i][1];
            }
            i++;
        }
        return ans;
        // return n-count;
    }
};