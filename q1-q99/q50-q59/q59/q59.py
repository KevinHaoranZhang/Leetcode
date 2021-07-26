class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        solution = [[0 for x in range(n)] for y in range(n)]
        count = 1
        layer = 0
        for layer in range(0, int ((n + 1)/2)):
            for ptr1 in range(layer, n - layer -1):
                solution[layer][ptr1] = count
                count += 1
            for ptr2 in range(layer, n - layer - 1):
                solution[ptr2][n - layer - 1] = count
                count += 1
            for ptr3 in range(n - layer -1, layer, -1):
                solution[n - layer - 1][ptr3] = count
                count += 1
            for ptr4 in range(n - layer - 1, layer, -1):
                solution[ptr4][layer] = count
                count += 1
        if n % 2:
            solution[int(n/2)][int(n/2)] = count
        return solution
