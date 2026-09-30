class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        bool o = true;
        bool c = true;
        vector<int> ans(n);
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                if(o){
                    ans[i] = 0;
                }    
                else ans[i] = 1;
                o = !o;
            }
            else{
                if(c) ans[i] = 0;
                else ans[i] = 1;
                c = !c;
            }
        }
        return ans;
    }
};