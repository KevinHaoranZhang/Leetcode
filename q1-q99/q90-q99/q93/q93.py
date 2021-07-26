class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans = []
        ip_segments = [0] * 4
        def back_track(index: int, cur_pos: int):
            if index == 4:
                if cur_pos == len(s):
                    ans.append(".".join (str(ip_segment) for ip_segment in ip_segments))
                return  
            if cur_pos == len(s):
                return
            if s[cur_pos] == '0':
                ip_segments[index] = 0
                back_track(index + 1, cur_pos + 1)
            addr = 0
            for i in range(cur_pos, len(s)):
                addr = addr * 10 + (ord(s[i]) - ord("0"))
                if 0 < addr <= 255:
                    ip_segments[index] = addr
                    back_track(index + 1, i + 1)
                else:
                    break
        back_track(0, 0)
        return ans
