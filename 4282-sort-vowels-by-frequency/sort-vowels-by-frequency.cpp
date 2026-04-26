class Solution {
public:
    bool isvowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string sortVowels(string s) {
        int n = s.size();
        vector<pair<int,char>> freq(26, {0, 0});
        vector<int> first(26, n); 
        for(int i = 0; i < n; i++){
            if(isvowel(s[i])){
                int idx = s[i] - 'a';
                freq[idx].first++;
                freq[idx].second = s[i];
                first[idx] = min(first[idx], i);
            }
        }
        sort(freq.begin(), freq.end(), [&](auto &a, auto &b){
            if(a.first != b.first) return a.first > b.first; 
            if(a.first == 0 || b.first == 0) return a.first > b.first;
            return first[a.second - 'a'] < first[b.second - 'a'];
        });
        int j = 0;
        for(int i = 0; i < n; i++){
            if(isvowel(s[i])){
                while(j < 26 && freq[j].first == 0) j++;
                if(j < 26){
                    s[i] = freq[j].second;
                    freq[j].first--;
                }
            }
        }
        return s;
    }
};