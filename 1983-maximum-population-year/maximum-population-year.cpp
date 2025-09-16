class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // int maxcount =0;
        // int val = 0;
        // for(int i=1950;i<=2050;i++){
        //     int count =0;
        //     for(int j=0;j<logs.size();j++){
        //         if(logs[j][0]<=i && logs[j][1]>i) count++;
        //     }
        //     if(count>maxcount){
        //         val = i;
        //         maxcount = count;
        //     }
        // }
        // return val;

        vector<int> population(101,0);
        for(auto &x:logs){
            population[x[0]-1950]++;
            population[x[1]-1950]--;
        }
        vector<int> pre(101);
        pre[0] = population[0];
        for(int i=1;i<101;i++){
            pre[i] = pre[i-1] + population[i];
        }
        int idx = -1;
        int maxvalue = 0;
        for(int i=0;i<101;i++){
            if(pre[i]>maxvalue){
                maxvalue = pre[i];
                idx = i;
            }
        }
        return idx+1950;
    }
};