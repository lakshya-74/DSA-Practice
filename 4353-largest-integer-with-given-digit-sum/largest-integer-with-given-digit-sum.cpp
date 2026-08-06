class Solution {
public:
    int largestInteger(int n, int s) {
        int num = 0;
        while(n--){
            num = num*10 + min(s,9);
            s -= min(s,9);
        }
        return s>0?-1:num;
    }
};