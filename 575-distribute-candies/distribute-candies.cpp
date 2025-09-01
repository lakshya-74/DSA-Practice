class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s;
        int n = candyType.size();
        for(int i=0;i<n;i++){
            s.insert(candyType[i]);
        }
        return min(n/2,(int)s.size());
    }
};