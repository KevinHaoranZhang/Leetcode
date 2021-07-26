class Solution {
private:
    vector<string> ans;
    vector<int> ip_segments;
public:
    vector<string> restoreIpAddresses(string s) {
        ip_segments.resize(4);
        back_track(0, 0, s);
        return ans;
    }

    void back_track(int index, int cur_pos, string str) {
        // the last segment
        if (index == 4) {
            // check if reach the end of ip string
            if (cur_pos == str.size()) {
                string ip_addr;
                for (int i = 0; i < 4; i++) {
                    if (i != 3) {
                        ip_addr += to_string(ip_segments[i]) + ".";
                    } else {
                        ip_addr += to_string(ip_segments[i]);
                    }
                }
                ans.push_back(ip_addr);
            }
            return;
        }

        // corner case: if not yet reach 4th segment, but already iterate over entire ip string
        if (cur_pos == str.size()) {
            return;
        }
        // corner case: reach 0, immediately invoke another call
        if (str[cur_pos] == '0') {
            ip_segments[index] = 0;
            back_track(index + 1, cur_pos + 1, str);
        }

        // general case
        int cur_ip_addr = 0;
        for (int i = cur_pos; i < str.size(); i++) {
            cur_ip_addr = cur_ip_addr * 10 + (str[i] - '0');
            if (cur_ip_addr > 0 && cur_ip_addr <= 255) {
                ip_segments[index] = cur_ip_addr;
                back_track(index + 1, i + 1, str);
            } else {
                break;
            }
        }
    }
};
