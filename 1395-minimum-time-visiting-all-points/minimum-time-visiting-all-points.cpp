class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time =0;
        int n = points.size();
        for(int i=1;i<n;i++){
            int x = abs(points[i][0] - points[i-1][0]);
            int y = abs(points[i][1] - points[i-1][1]);
            time += min(x,y);
            time += max(x,y) - min(x,y);
        }
        return time;
    }
};