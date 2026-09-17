class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [1] * n

        # Calculate prefix product for each element
        for i in range(1, n):
            ans[i] = ans[i - 1] * nums[i - 1]

        suffix = 1
        # Calculate suffix product and multiply it to the prefix product
        for i in range(n - 2, -1, -1):
            suffix *= nums[i + 1]
            ans[i] *= suffix

        return ans

