class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int es) {
        priority_queue<vector<double>> pq;
        for(int i=0;i<classes.size();i++){
            double p = classes[i][0];
            double t = classes[i][1];
            double g = (p+1)/(t+1) - (p/t);
            pq.push({g,p,t});
        }
        int n = classes.size();
        while(es--){
            auto curr = pq.top();
            pq.pop();
            double x = curr[1]+1;
            double y = curr[2]+1;
            double g = (x+1)/(y+1) - (x/y);
            pq.push({g,x,y});
        }
        double ans = 0;
        while(!pq.empty()){
            ans += pq.top()[1]/pq.top()[2];
            pq.pop();
        }
        return ans/n;
    }
};