class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        map<int,int> mpp;
        for(auto &x:digits){
            mpp[x]++;
        }
        vector<int> ans;
        for(int i=100;i<=999;i+=2){
            int x = i;
            int a = x%10;
            x /=10;
            int b = x%10;
            x /= 10;
            int c = x;
            if(mpp.find(a)!=mpp.end()){
                mpp[a]--;
                if(mpp[a]==0) mpp.erase(a);
                if(mpp.find(b)!=mpp.end()){
                    mpp[b]--;
                    if(mpp[b]==0) mpp.erase(b);
                    if(mpp.find(c)!=mpp.end()){
                        ans.push_back(i);
                    }
                    mpp[b]++;
                }
                mpp[a]++; // add for next iteration
            }
        }
        return ans;
    }
};