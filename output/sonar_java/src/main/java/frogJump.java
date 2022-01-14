import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/** https://leetcode.com/problems/frog-jump/ */
//A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
//Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
//If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

class frogJump {
    public boolean canCross(int[] stones) {
        if (stones == null || stones.length == 0) {
            return false;
        }
        if (stones.length == 1) {
            return true;
        }
        Map<Integer, Set<Integer>> jumpMap = new HashMap<>();
        for (int i = 0; i < stones.length; i++) {
            jumpMap.put(stones[i], new HashSet<>());
        }
        jumpMap.get(stones[0]).add(1);
        for (int i = 1; i < stones.length; i++) {
            for (int j : jumpMap.get(stones[i - 1])) {
                int jump = stones[i] - stones[i - 1] + j;
                if (jump > 0 && jumpMap.get(stones[i]).add(jump)) {
                    if (jump == stones[stones.length - 1] - stones[i]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}