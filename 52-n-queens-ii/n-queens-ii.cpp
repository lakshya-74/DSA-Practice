class Solution {
public:
bool check_valid(int row ,int col,vector<int>& queens){
    for(int i=0;i<row;i++){
        int prow = i; // my previous row
        int pcol = queens[i]; // previous col where queen is already palced
        if(pcol==col || abs(prow-row)==abs(pcol-col)) return false;
    }    
    return true;
}
int rec(int level , int n , vector<int>& queens){
    // base case
    if(level==n){
        return 1; // done 1 possible way
    }
    int ans = 0;
    for(int cols=0;cols<n;cols++){
        if(check_valid(level,cols,queens)){
            queens[level] = cols; // place the queen
            ans += rec(level+1,n,queens); // explore the options
            queens[level] = -1; // revert the queen positions
        }
    }
    return ans;
}
    int totalNQueens(int n) {
        vector<int> queens(n,-1);
        return rec(0,n,queens);
    }
};