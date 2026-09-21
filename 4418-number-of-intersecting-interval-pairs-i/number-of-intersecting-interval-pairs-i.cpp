class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        for(int i=0;i<intervals.size()-1;i++){
            auto curr = intervals[i];
            for(int j=i+1;j<intervals.size();j++){
                auto next = intervals[j];
                if(max(curr[0],next[0])<=min(curr[1],next[1])) ans++;
            }
        }
        return ans;
    }
};