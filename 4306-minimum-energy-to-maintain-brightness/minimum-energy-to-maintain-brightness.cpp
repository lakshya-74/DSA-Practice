class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int m = intervals.size();
        sort(intervals.begin(),intervals.end());
        long long on = ceil(brightness/3.0);
        vector<vector<int>> v;
        for(auto curr:intervals){
            if(v.empty() || curr[0]>v.back()[1]){
                v.push_back(curr);
            }
            else{
                v.back()[1] = max(v.back()[1],curr[1]); 
            }
        }
        long long len =0;
        for(int i=0;i<v.size();i++){
            long long dist = v[i][1] - v[i][0] + 1;
            len += dist;
        }
        return len*on;
    }
};