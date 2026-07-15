class Solution {
public:
    int rec(int idx, vector<string>& words , map<char,int>&mpp, vector<int>& score){
        if(idx<0) return 0;
        int a = rec(idx-1,words,mpp,score);
        bool flag = true;
        int b = 0;
        int ans = 0;
        for(auto x:words[idx]){
            if(mpp[x]<=0){
                flag = false;
            }
            int p = int(x);
            ans += score[p-97];
            mpp[x]--;
        }    
        if(!flag){
            for(auto x:words[idx]){
                mpp[x]++;
            }
            b = rec(idx-1,words,mpp,score);
        }
        else{
            b = ans + rec(idx-1,words,mpp,score);
            for(auto x:words[idx]){
                mpp[x]++;
            }
        }
        return max(a,b);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        map<char,int> mpp;
        for(int i=0;i<letters.size();i++){
            mpp[letters[i]]++;
        }
        return rec(n-1,words,mpp,score);
    }
};