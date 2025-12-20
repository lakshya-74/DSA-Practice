class Solution {
public:
    static bool cmp(vector<int>&p1 , vector<int>&p2){
        return p1[1]>p2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int total=0;
        for(int i=0;i<boxTypes.size();i++){
            vector<int> curr = boxTypes[i];
            if(curr[0]<=truckSize){
                total += curr[1]*curr[0];
                truckSize -= curr[0];
            }
            else{
                total += curr[1]*truckSize;
                break;
            }
        }
        return total;
    }
};