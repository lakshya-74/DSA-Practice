class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        unordered_set<char> st ,st1 , st2;
        for(int i=0;i<n;i++){
            if(word[i]>='A' && word[i]<='Z'){
                if(st.count(word[i])){
                    word[i] = '*';
                }
                else st.insert(word[i]);
            }
        }
        vector<int> check(26,0);
        for(int i=n-1;i>=0;i--){
            if(word[i]>='a' && word[i]<='z'){
                if(st2.count(char(word[i]-32))) check[word[i]-'a'] =1;
                st1.insert(word[i]);
            }
            else if(word[i]>='A' && word[i]<='Z'){
                if(st1.count(char(word[i]+32))) continue;
                st2.insert(word[i]);
            }
        }
        int ans =0;
        for(int i=0;i<26;i++){
            ans += check[i];
        }
        return ans;
    }
};