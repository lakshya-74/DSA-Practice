class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = INT_MAX;
        int idx = -1;
        for(int i=0;i<drones.size();i++){
            int dist = abs(target[0] - drones[i][0]) + abs(target[1]-drones[i][1]);
            if(dist<=drones[i][2]){
                if(dist<ans){
                    ans = dist;
                    idx = i;
                }
            }
        }
        return idx;
    }
};