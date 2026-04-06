class Solution {
public:
    bool judgeCircle(string moves) {
        int countl = 0 , countu = 0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L') countl++;
            else if(moves[i]=='R') countl--;
            else if(moves[i]=='U') countu++;
            else countu--;
        }
        return (countl==0 && countu==0);
    }
};