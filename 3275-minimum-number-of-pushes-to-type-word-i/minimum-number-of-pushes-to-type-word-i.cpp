class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26,0);
        int n = word.size();
        for(int i=0;i<n;i++){
            v[word[i]-'a']++;
        }
        sort(v.rbegin(),v.rend());
        int ans = 0;
        int j= 2;
        int freq = 1;
        for(int i=0;i<26;i++){
            while(v[i]>0){
                ans += freq;
                j++;
                if(j>9){
                    j= 2;
                    freq++;
                }
                v[i]--;
            }
        }
        return ans;
    }
};