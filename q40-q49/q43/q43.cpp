class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        string s(n + m, '0');
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                int p = (num1[i] - '0') * (num2[j] - '0') + (s[i + j + 1] - '0');
                s[i+j+1] = p % 10 + '0';
                s[i+j] += p / 10 ;
            }
       }
       for(int i = 0; i < m + n; i++)
       {
          if(s[i] !='0')
			  return s.substr(i);
       }
       return "0";
    }
};
