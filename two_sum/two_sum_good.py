class Solution(object):
    def twoSum(self, nums, target):
        hash = {}
        for i in range(len(nums)):
            num = nums[i]
            complement = target - num
            if complement in hash:
                return [hash[complement], i]
            hash[num] = i
        return []