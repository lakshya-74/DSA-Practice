class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        int total = 0;
        for(int i =0;i<answers.size();i++){
            if(mp.find(answers[i])==mp.end()) total += answers[i]+1;
            mp[answers[i]]++;
            if(mp[answers[i]]==answers[i]+1) mp.erase(answers[i]);
        }
        return total;
    }
};