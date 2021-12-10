/** https://leetcode.com/problems/super-ugly-number/ */
//A super ugly number is a positive integer whose prime factors are in the array primes.
//Given an integer n and an array of integers primes, return the nth super ugly number.
//The nth super ugly number is guaranteed to fit in a 32-bit signed integer.



int nthSuperUglyNumber(int n, int* primes, int primesSize){
    int* dp = malloc(sizeof(int) * n);
    dp[0] = 1;
    int* index = malloc(sizeof(int) * primesSize);
    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < primesSize; j++) {
            dp[i] = min(dp[i], dp[index[j]] * primes[j]);
        }
        for (int j = 0; j < primesSize; j++) {
            if (dp[i] == dp[index[j]] * primes[j]) {
                index[j]++;
            }
        }
    }
    int result = dp[n - 1];
    free(dp);
    free(index);
    return result;
    
}
    