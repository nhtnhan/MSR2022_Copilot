/** https://leetcode.com/problems/frog-jump/ */
//A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
//Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
//If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

/**
 * @param {number[]} stones
 * @return {boolean}
 */
 var canCross = function(stones) {
    let map = new Map();
for(let i = 0; i < stones.length; i++) {
   map.set(stones[i], new Set());
}
for(let i = 0; i < stones.length; i++) {
   for(let j = i + 1; j < stones.length; j++) {
       if(stones[j] - stones[i] <= 2) {
           map.get(stones[i]).add(stones[j]);
       }
   }
}
let visited = new Set();
return dfs(0, map, visited);
}
