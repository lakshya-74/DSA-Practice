class Solution {
public:
    int elevatorRequests(int n, vector<int>& req) {
        int sum = req[0];
        for(int i=1;i<req.size();i++){
            sum += abs(req[i-1]-req[i]);
        }
        return sum;
    }
};