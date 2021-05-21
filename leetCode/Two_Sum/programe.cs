public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var dec = new Dictionary<int, int>();
                for (int i = 0; i < nums.Length; i++)
                {
                    var rest = target - nums[i];
                    if (dec.ContainsKey(rest))
                    {
                        return new int[]{dec[rest], i};
                    }

                    dec[nums[i]] = i;
                }

                throw new ArgumentException("Not Found");
    }
}