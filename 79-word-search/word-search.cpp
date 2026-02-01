class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool check(int i ,int j ,vector<vector<char>>& arr,string s){
        if(s.size()==0) return true;
        int n = arr.size();
        int m = arr[0].size();
        if(i<0 || i>=n || j<0 || j>=m || arr[i][j]!=s[0]) return false;
        char ch = arr[i][j];
        arr[i][j] = '-1';
        string st = s.substr(1);
        bool ans = false;
        for(int k=0;k<4;k++){
            int r = i+dx[k];
            int c = j+dy[k];
            ans |= check(r,c,arr,st);
        }
        arr[i][j] = ch;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool ans = check(i,j,board,word);
                if(ans) return true;
            }
        }
        return false;
    }
};