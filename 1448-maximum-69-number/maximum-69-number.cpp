class Solution {
public:
    int maximum69Number (int num) {
        int ans = 0;
        vector<int> check;
        int a = num;
        while(a>0){
            check.push_back(a%10);
            a = a/10;
        }
        for(int i=check.size()-1;i>=0;i--){
            if(check[i]==6){
                check[i] = 9;
                break;
            }
        }
        
        for(int i=check.size()-1;i>=0;i--){
            ans += check[i];
            ans *= 10;
        }
        return ans/10;
    }
};