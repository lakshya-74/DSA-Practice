class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        sort(intervals.begin(),intervals.end(),[](vector<int>& a, vector<int>& b){
            if(a[0]==b[0]) return (a[1]-a[0]) > (b[1]-b[0]);
            return a[0]<b[0];
        });
        for(int i=0;i<n-1;){
            int j = i+1;
            while(j<n && intervals[i][1]>=intervals[j][1]){
                count++;
                j++;
            }
            i = j;
        }
        return n-count;
    }
};