/** https://leetcode.com/problems/can-i-win/ */
//In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.
//What if we change the game so that players cannot re-use integers?
//For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.
//Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.

class canIWin {
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        boolean[] dp = new boolean[1 << maxChoosableInteger];
        return helper(dp, maxChoosableInteger, desiredTotal);
    }

    private boolean helper(boolean[] dp, int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return false;
        if (maxChoosableInteger <= 0) return true;
        int mask = 1 << maxChoosableInteger;
        if (dp[mask - 1]) return true;
        for (int i = 1; i <= maxChoosableInteger; i++) {
            if ((mask & (1 << i)) == 0) {
                if (!helper(dp, maxChoosableInteger - 1, desiredTotal - i)) {
                    dp[mask - 1] = true;
                    return true;
                }
            }
        }
        return false;
    }
}
