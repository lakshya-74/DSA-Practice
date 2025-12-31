class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = s[i]-'a';
        }
        vector<int> diff(n+1,0);
        for(int i=0;i<shifts.size();i++){
            int change = shifts[i][2];
            if(change==1){
                diff[shifts[i][0]]++;
                diff[shifts[i][1]+1]--;
            }
            else{
                diff[shifts[i][0]]--;
                diff[shifts[i][1]+1]++;
            }
        }
        for(int i=1;i<n;i++){
            diff[i] += diff[i-1];
        }
        string st="";
        for(int i=0;i<n;i++){
            int shift = diff[i]%26;
            int new_char = (s[i]-'a' + shift + 26)%26;
            st += char('a' + new_char);
        }
        return st;
    }
};