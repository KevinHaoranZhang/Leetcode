ans = int(dividend//divisor)
        if int(dividend//divisor) < dividend/divisor:
            ans = dividend/divisor
        if ans > 2**31 - 1:
            return 2**31-1
        return int(ans)
