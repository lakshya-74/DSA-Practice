class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        double ans = 0;
        int result = 0;
        for(int i=0;i<d.size();i++){
            double check = sqrt((1.0)*(d[i][0]*d[i][0])+(1.0)*(d[i][1]*d[i][1]));
            if(check>ans){
                ans = check;
                result = d[i][0]*d[i][1];
            }
            else if(check==ans){
                result = max(result,d[i][0]*d[i][1]);
            }
        }
        return result;
    }
};