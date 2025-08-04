class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> q;
        queue<int> r;
        queue<int> d;
        for(int i=0;i<n;i++){
            q.push(i);
            if(senate[i]=='R') r.push(i);
            else d.push(i);
        }
        while(q.size()){
            int i = q.front();
            if(senate[i]=='R'){
                if(d.size()==0) return "Radiant";
                senate[d.front()] = 'x';
                d.pop();
                q.push(i);
                q.pop();
                r.push(r.front());
                r.pop();
            }
            else if(senate[i]=='D'){
                if(r.size()==0) return "Dire";
                senate[r.front()] = 'x';
                r.pop();
                q.push(i);
                q.pop();
                d.push(d.front());
                d.pop();
            }
            else q.pop();
        }
        return "a";
    }
};