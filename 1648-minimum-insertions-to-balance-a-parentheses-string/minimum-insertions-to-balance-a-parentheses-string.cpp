class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int i = 0;
        int count = 0;
        int n = s.size();
        while(i<s.size()){
            bool flag = false;
            if(s[i]=='('){
                count++;
            }
            else{
                count--;
                if(count<0){
                    if(i<n-1 && s[i+1]==')'){
                        ans++;
                        flag = true;
                    }
                    else{
                        ans += 2;
                    }
                    count =0;
                }
                else{
                    if(i<n-1 && s[i+1]==')'){
                        flag = true;
                    }
                    else ans++;
                }
            }
            if(flag) i++;
            i++;
        }
        ans += count*2;
        return ans;
    }
};