bool isPalindrome(int x) {
    int num = x;
    if(num < 0) {
        return false;
    }

    int temp = num;
    long long revNum = 0;
    while(temp > 0) {
        int digit = temp % 10;
        revNum = revNum * 10 + digit;
        temp = temp / 10;
    }

    return num == revNum;
}