class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int mn = INT_MAX;
        for(int i=0;i<tasks.size();i++){
            mn = min(mn,tasks[i][0]+tasks[i][1]);
        }
        return mn;
    }
};