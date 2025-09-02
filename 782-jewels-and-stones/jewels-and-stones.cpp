class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int> mpp;
        int n = stones.size();
        for(int i=0;i<n;i++){
            mpp[stones[i]]++;
        }
        int count =0;
        for(int i=0;i<jewels.size();i++){
            for(auto x:mpp){
                if(x.first==jewels[i]) count += x.second;
            }
        }
        return count;
    }
};