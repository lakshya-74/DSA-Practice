class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        int n = words.size();
        for(int i=0;i<n;i++){
            int sum =0;
            for(int j=0;j<words[i].size();j++){
                sum += weights[words[i][j]-'a'];
            }
            sum = sum%26;
            ans += (char)(96 + 26 - sum);
        }
        return ans;
    }
};