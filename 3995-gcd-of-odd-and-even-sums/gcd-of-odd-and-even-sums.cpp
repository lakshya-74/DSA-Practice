class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 0;
        int even =0;
        int i=1;
        int oddcount =0;
        while(oddcount<n){
            odd += i;
            oddcount++;
            i+=2;
        }
        i = 2;
        int evencount =0;
        while(evencount<n){
            even += i;
            evencount++;
            i+= 2;
        }
        return gcd(odd,even);
    }
};