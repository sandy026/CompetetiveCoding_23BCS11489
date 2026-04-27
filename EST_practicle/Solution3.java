import java.util.*;

class Solution3 {
    public ArrayList<ArrayList<Integer>> findSubsets(int[] arr) {
        Arrays.sort(arr);

        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        backtrack(0, arr, new ArrayList<>(), result);

        return result;
    }

    private void backtrack(int start, int[] arr, ArrayList<Integer> subset,
                           ArrayList<ArrayList<Integer>> result) {

        result.add(new ArrayList<>(subset));

        for (int i = start; i < arr.length; i++) {

            if (i > start && arr[i] == arr[i - 1]) continue;

            subset.add(arr[i]);
            backtrack(i + 1, arr, subset, result);
            subset.remove(subset.size() - 1);
        }
    }
}