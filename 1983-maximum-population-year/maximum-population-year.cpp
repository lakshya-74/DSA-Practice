class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int maxcount =0;
        int val = 0;
        for(int i=1950;i<=2050;i++){
            int count =0;
            for(int j=0;j<logs.size();j++){
                if(logs[j][0]<=i && logs[j][1]>i) count++;
            }
            if(count>maxcount){
                val = i;
                maxcount = count;
            }
        }
        return val;
    }
};