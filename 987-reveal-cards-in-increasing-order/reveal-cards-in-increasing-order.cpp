class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(),deck.end());
        queue<int> q;
        for(int i=1;i<n;i++){
            q.push(i);
        }
        vector<int> ans(n);
        ans[0] = deck[0];
        int i=1;
        while(q.size()){
            q.push(q.front());
            q.pop();
            ans[q.front()] = deck[i];
            i++;
            q.pop();  
        }
        return ans;
    }
};