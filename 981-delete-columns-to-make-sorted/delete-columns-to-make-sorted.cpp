class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int k = strs[0].size();
        int n = strs.size();
        int j =0;
        int count = 0;
        while(k--){
            char mx = 'a';
            for(int i=0;i<n;i++){
                if(strs[i][j]>=mx){
                    mx = strs[i][j];
                }
                else{
                    count++;
                    break;
                }
            }
            j++;
        }
        return count;
    }
};