class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(goal.size()!=n) return false;
        s = s+s;
        for(int i=0;i<n;i++){
            for(int j=i;j<2*n;j++){
                string st = s.substr(i,j-i+1);
                if(st==goal) return true; 
            }
        }
        return false;
    }
};