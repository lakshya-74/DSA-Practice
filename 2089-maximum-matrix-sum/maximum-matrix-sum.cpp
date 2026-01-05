class Solution {
public:
    #define ll long long
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll sum =0;
        int n = matrix.size();
        int neg = 0;
        int mx_neg = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j]<0) neg++;
                mx_neg = min(mx_neg,abs(matrix[i][j]));
            }
        }
        if(neg&1){
            sum -= 2*(mx_neg);
        }
        return sum;
    }
};