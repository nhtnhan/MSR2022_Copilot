/** https://leetcode.com/problems/count-numbers-with-unique-digits/ */
//Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.



int countNumbersWithUniqueDigits(int n){
    if(n==0) return 1;
    int res=10;
    int base=9;
    for(int i=2;i<=n;i++){
        base*=10-i+1;
        res+=base;
    }
    return res;
}
    