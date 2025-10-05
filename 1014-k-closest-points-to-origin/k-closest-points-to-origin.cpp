class Solution {
public:
    typedef pair<int,vector<int>> pp;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pp> pq;
        for(int i=0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            int z = x*x + y*y;
            pq.push({z,points[i]});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};