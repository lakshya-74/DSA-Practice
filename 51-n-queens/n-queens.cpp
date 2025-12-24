class Solution {
public:
    vector<vector<string>> ans;
    bool check_valid(int row ,int col,vector<int>& queens){
        for(int i=0;i<row;i++){
            int prow = i; // my previous row
            int pcol = queens[i]; // previous col where queen is already palced
            if(pcol==col || abs(prow-row)==abs(pcol-col)) return false;
        }    
        return true;
    }
    void rec(int level , int n , vector<int>& queens){
        // base case
        if(level==n){
            vector<string> s(n,string(n,'.'));
            for(int i=0;i<n;i++){
                if(queens[i]!=-1){
                    s[i][queens[i]] = 'Q';
                }
            }
            ans.push_back(s);
            return; // done 1 possible way
        }
        for(int cols=0;cols<n;cols++){
            if(check_valid(level,cols,queens)){
                queens[level] = cols; // place the queen
                rec(level+1,n,queens); // explore the options
                queens[level] = -1; // revert the queen positions
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> queens(n,-1);
        rec(0,n,queens);
        return ans;
    }
};