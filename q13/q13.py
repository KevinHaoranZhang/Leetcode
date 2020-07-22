class Solution:
    def romanToInt(self, s: str) -> int:
        solution = 0
        i = 0
        while i < len(s):
            if (s[i] == 'I'):
                if ((i+1) < len(s)):
                    if(s[i+1] == 'V'):
                        solution += 4
                        i += 2
                    elif(s[i+1] == 'X'):
                        solution += 9
                        i += 2
                    else:
                        solution += 1
                        i += 1
                else:
                    solution += 1
                    i += 1
            elif (s[i] == 'V'):
                solution += 5
                i += 1
            elif (s[i] == 'X'):
                if ((i+1) < len(s)):
                    if(s[i+1] == 'L'):
                        solution += 40
                        i += 2
                    elif(s[i+1] == 'C'):
                        solution += 90
                        i += 2
                    else:
                        solution += 10
                        i += 1
                else:
                    solution += 10
                    i += 1
            elif (s[i] == 'L'):
                solution += 50
                i += 1
            elif (s[i] == 'C'):
                if ((i+1) < len(s)):
                    if(s[i+1] == 'D'):
                        solution += 400
                        i += 2
                    elif(s[i+1] == 'M'):
                        solution += 900
                        i += 2
                    else:
                        solution += 100
                        i += 1
                else:
                    solution += 100
                    i += 1
            elif (s[i] == 'D'):
                solution += 500
                i += 1
            elif (s[i] == 'M'):
                solution += 1000
                i += 1
        return solution
