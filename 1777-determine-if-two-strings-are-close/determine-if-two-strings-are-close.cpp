class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        map<char,int> mpp1,mpp2;
        for(int i=0;i<word1.size();i++){
            mpp1[word1[i]]++;
            mpp2[word2[i]]++;
        }
        for(auto x:mpp1){
            if(mpp2.find(x.first)==mpp2.end()) return false;
        }
        map<char,int> h1,h2;
        for(auto x:mpp1){
            h1[x.second]++;
        }
        for(auto x:mpp2){
            h2[x.second]++;
        }
        for(auto x:h1){
            if(h2.find(x.first)==h2.end()) return false;
            if(h2[x.first]!=h1[x.first]) return false;
        }
        return true;
    }    
};