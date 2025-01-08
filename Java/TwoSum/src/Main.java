import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        int[] nums = {3, 3};
        System.out.println(Arrays.toString(twoSum(nums, 6)));
    }
    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numsIndex = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
            Integer rest = numsIndex.get(nums[i]);
            if(rest!= null) {
                return new int[]{i, rest};
            }
                numsIndex.put(target - nums[i], i);
        }
        return nums;
    }
}