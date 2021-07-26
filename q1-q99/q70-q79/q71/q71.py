class Solution:
    def simplifyPath(self, path: str) -> str:
        path_name = []
        solution = "/"
        i = 0
        size = len(path)
        while i < size:
            word = ""
            while i < size and path[i] != "/":
                word += path[i]
                i += 1
            if word == "..":
                if len(path_name) > 0:
                    path_name.pop()
            elif word != "" and word != ".":
                path_name.append(word)
            i += 1
        for i in path_name:
            solution += i + "/"
        if solution == "/":
            return solution
        return solution[0:len(solution) - 1]
