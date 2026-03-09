class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        bool flag = false;
        vector<int> arr = code;
        for(int i=0;i<n;i++){
            arr.push_back(code[i]);
        }
        if(k==0){
            for(int i=0;i<n;i++){
                code[i] = 0;
            }
        }
        else{
            if(k<0){
                reverse(arr.begin(),arr.end());
                flag = true;
                k = -k;
            }
            int l = 0 , r = 1;
            int sum = 0;
            while(r<2*n-1){
                sum += arr[r];
                if(r-l>k){
                    l++;
                    sum -= arr[l];
                }
                if(l>=n) break;
                if(r-l==k){
                    code[l] = sum;
                }
                r++;
            }
        }
        if(flag){
            reverse(code.begin(),code.end());
            return code;
        }
        return code;
    }
};