class Solution {
public:
    int countCommas(int n) {
        // int count =0;
        // int check = 3;
        // int a = 1000;
        // int b = 10000;
        // if(n>=a){
        //     count += n-a + 1;
        // }
        // return count;
        return max(n-1000+1,0);
    }
};