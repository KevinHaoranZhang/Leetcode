from collections import deque
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        matching = {")": "(", "}": "{", "]": "["}
        for char in s:
            if char in matching:
                top = stack.pop() if stack else '#'
                if matching[char] != top:
                    return False
            else:
                stack.append(char)
                
        return not stack
