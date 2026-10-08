class Solution:
    def sortArrayByParity(self, nums: list[int]) -> list[int]:
        start = 0

        for i in range(len(nums)):
            if nums[i] % 2 == 0:
                nums[start], nums[i] = nums[i], nums[start]
                start += 1

        return nums