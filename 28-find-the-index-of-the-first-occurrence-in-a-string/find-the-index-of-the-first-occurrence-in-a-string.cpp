class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0 , j = 0;
        while(i<haystack.size()){
            int j = 0;
            int k = i;
            while(k<
            haystack.size() && j<needle.size() && haystack[k]==needle[j]){
                k++;
                j++;
            };
            if(j==needle.size()) return i;
            i++;
        }
        return -1;
    }
};