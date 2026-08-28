class Solution {
public:
    void rec(int i,int j, string& target , string& str , map<char,int>& mpp,bool& check){
        int n = target.size();
        if(check){
            while(i<j){
                bool flag = false;
                for(auto& x:mpp){
                    if(x.second>=2){
                        str[i++] = x.first;
                        str[j--] = x.first;
                        x.second -= 2;
                        flag = true;
                        break;
                    }
                }
                if(!flag) return;
            }
            if(i==j){
                for(auto& x:mpp){
                    if(x.second>0){
                        str[i] = x.first;
                        mpp[x.first]--;
                        return; 
                    }
                }
            }
            return;
        }
        if(i>j){
            if(str>target) check = true;
            return;
        }
        if(i==j){
            for(auto& x:mpp){
                if(x.second==1){
                    str[i] = x.first;
                    mpp[x.first]--;
                    if(str>target) check = true;
                    return;
                    mpp[x.first]++;
                    str[i] = '0';
                    return;
                }
            }
            return;
        }
        if(mpp[target[i]]>=2){
            mpp[target[i]] -= 2;
            str[i] = target[i];
            str[j] = target[i];
            rec(i+1,j-1,target,str,mpp,check);
            if(check) return;
            mpp[target[i]] += 2;
            str[i] = '0';
            str[j] = '0';
        }
        char mn = '{';
        for(auto& x:mpp){
            if(x.first>target[i] && x.second>=2){
                mn = x.first;
                break;
            }
        }
        if(mn!='{'){
            mpp[mn] -= 2;
            str[i] = mn;
            str[j] = mn;
            check = true;
            rec(i+1,j-1,target,str,mpp,check);
            return;
        }
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        map<char,int> mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        int odd = 0;
        for(auto x:mpp){
            if(x.second%2==1) odd++;
        }
        if(odd>1) return "";
        string str(n,'0');
        bool check = false;
        rec(0,n-1,target,str,mpp,check);
        // bool flag = true;
        // for(int i=0;i<n;i++){
        //     if(str[i]=='0'){
        //         flag= false;
        //         break;
        //     }
        // }
        if(check) return str;
        return "";
    }
};