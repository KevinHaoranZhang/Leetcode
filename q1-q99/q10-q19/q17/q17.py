from queue import Queue
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        solution = []
        if not len(digits):
            return solution
        phone = [ " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        q = Queue()
        q.put("")
        for char in digits:
            index = int (char) - int("0")
            print(index)
            i = q.qsize()
            while i != 0:
                i -= 1
                top = q.get()
                for phone_char in phone[index]:
                    q.put(top+phone_char)
        while not q.empty():
            solution.append(q.get())
        return solution
                    
        
