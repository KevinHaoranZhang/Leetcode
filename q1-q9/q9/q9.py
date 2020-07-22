class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x != 0 and x % 10 == 0):
            return False
        partial_revert = 0
        while ( x > partial_revert):
            partial_revert = int (partial_revert * 10 + x % 10)
            x = int (x / 10)

        return x == partial_revert or x == int (partial_revert / 10)
