class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        solution = 0;
        current_sum = 0;
        current_diff = inf;
        nums.sort();
        for i in range(0, len(nums)-2):
            left = i + 1;
            right = len(nums) - 1;
            while left < right:
                current_sum = nums[i] + nums[left] + nums[right];
                if abs(target - current_sum) < current_diff:
                    current_diff = abs(target - current_sum);
                    solution = current_sum;
                if current_sum < target:
                    left += 1;
                elif current_sum > target:
                    right -= 1;
                else:
                    return target;
        return solution;
