class Solution {
public:
    int single_element(string s, char ch){
        int count = 1;
        int mx = 1;
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                mx = max(mx,count);
                count = 1;
            }
            else count++;
        }
        mx = max(mx,count);
        return mx;
    }
    int double_element(string s, char c1 , char c2){
        int ans = 0;
        map<int,int> mpp;
        int count1 = 0; // c1
        int count2 = 0; // c2
        for(int i=0;i<s.size();i++){
            if(s[i]==c1) count1++;
            else if(s[i]==c2) count2++;
            else{
                count1 = 0;
                count2 = 0;
                mpp.clear();
            }
            if(count1==count2){
                ans = max(ans,count1+count2);
            }
            else{
                int diff = count1 - count2;
                if(mpp.find(diff)!=mpp.end()){
                    ans = max(ans,i-mpp[diff]);
                }
                else mpp[diff] = i;
            }
        }
        return ans;
    }
    int triple_element(string s){
        int ans =  0;
        map<pair<int,int>,int> mpp;
        int count1 = 0;
        int count2 =0;
        int count3 = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a') count1++;
            else if(s[i]=='b') count2++;
            else count3++;
            if(count1==count2 && count2==count3){
                ans = max(ans,count1+count2+count3);
            }
            else{
                int diff1 = count1 - count2;
                int diff2 = count1 - count3;
                if(mpp.find({diff1,diff2})!=mpp.end()){
                    ans = max(ans,i-mpp[{diff1,diff2}]);
                }
                else mpp[{diff1,diff2}] = i;
            }
        }
        return ans;
    }
    int longestBalanced(string s) {
        int ans = 0;
        int a1 = single_element(s,'a');
        int a2 = single_element(s,'b');
        int a3 = single_element(s,'c');
        int x = max(a1,max(a2,a3));
        ans = max(ans,x);

        a1 = double_element(s,'a','b');
        a2 = double_element(s,'a','c');
        a3 = double_element(s,'b','c');
        x = max(a1,max(a2,a3));
        ans = max(ans,x);

        a1 = triple_element(s);
        ans = max(ans,a1);
        return ans;
    }
};