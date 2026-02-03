class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;

    long long prev2 = 1;
        long long prev1 = (s[0] == '*') ? 9 : 1;
        int mod=1e9+7;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            long long val = 0;
            if (s[i] == '*') {

                // 1 digit
                val = (9 * prev1);

                // 2 digit
                if (s[i - 1] == '*')
                    val += (15 * prev2);
                else if (s[i-1] == '2')
                    val += (6 * prev2);
                else if (s[i-1] == '1')
                    val += (9 * prev2);

            } else if (s[i] == '0') {

                // 1 digit
                val = 0;

                // 2 digit
                if (s[i - 1] == '*') val += 2*prev2;
                else if( s[i-1] == '1' || s[i-1] == '2') val += prev2;
                    

            } else {
                // 1 digit
                val = prev1;

                if (s[i - 1] == '*') {
                    if (s[i] > '6')
                        val += prev2;
                    else
                        val += (2 * prev2);
                } else if (s[i - 1] == '2' && s[i] <= '6')
                    val += prev2;
                else if (s[i - 1] == '1')
                    val += prev2;
            }

            prev2 = prev1%mod;
            prev1 = val%mod;
        }

        return prev1;
    }
};