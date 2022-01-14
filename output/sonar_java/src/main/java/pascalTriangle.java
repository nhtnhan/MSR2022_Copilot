import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/** https://leetcode.com/problems/pascals-triangle/ */

class pascalTriangle {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        if (numRows == 0) return result;
        result.add(Arrays.asList(1));
        if (numRows == 1) return result;
        result.add(Arrays.asList(1, 1));
        if (numRows == 2) return result;
        for (int i = 2; i < numRows; i++) {
            List<Integer> cur = new ArrayList<>();
            cur.add(1);
            for (int j = 1; j < i; j++) {
                cur.add(result.get(i - 1).get(j - 1) + result.get(i - 1).get(j));
            }
            cur.add(1);
            result.add(cur);
        }
        return result;
    }
}