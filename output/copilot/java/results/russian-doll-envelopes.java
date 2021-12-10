/** https://leetcode.com/problems/russian-doll-envelops/ */
//You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
//One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
//Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
//Note: You cannot rotate an envelope.

class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int[] dp = new int[envelopes.length];
        int max = 0;
        for (int i = 0; i < envelopes.length; i++) {
            int height = envelopes[i][1];
            int left = 0;
            int right = max;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (dp[mid] < height) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            dp[left] = height;
            if (left == max) {
                max++;
            }
        }
        return max;
    }
}