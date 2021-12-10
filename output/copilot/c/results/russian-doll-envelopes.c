/** https://leetcode.com/problems/russian-doll-envelops/ */
//You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
//One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
//Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
//Note: You cannot rotate an envelope.



int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    int max = 0;
    int* dp = (int*)malloc(sizeof(int)*envelopesSize);
    for(int i = 0; i < envelopesSize; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max = max(max, dp[i]);
    }
    return max;
}
    