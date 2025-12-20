class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<char,int>> pq;
        for(auto x:mp){
            pq.push(x);
        }
        string result = "";
        while(pq.size()){
            auto largest = pq.top();
            pq.pop();
            int len = min(repeatLimit,largest.second);
            for(int i=0;i<len;i++){
                result += largest.first;
            }
            pair<char,int> secondL;
            if(largest.second - len>0){
                if(pq.size()){
                    secondL = pq.top();
                    pq.pop();
                    result += secondL.first;
                }
                else return result;
                if(secondL.second>1){
                    pq.push({secondL.first,secondL.second-1});
                }
                pq.push({largest.first,largest.second-len});
            }
        }
        return result;
    }
};