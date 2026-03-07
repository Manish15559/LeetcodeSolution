class Solution {
public:
    int minFlips(string s) {
        int oddZero = 0, oddOne = 0, evenOne = 0, evenZero = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i % 2 == 1)
                    oddZero++;
                else
                    evenZero++;
            } else {
                if (i % 2 == 1)
                    oddOne++;
                else
                    evenOne++;
            }
        }
      
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            // consider its start with zero
            ans =
                min(ans, ((((n + 1) / 2) - evenZero) + ((((n) / 2) - oddOne))));
            ans =
                min(ans, ((((n + 1) / 2) - evenOne) + ((((n) / 2) - oddZero))));
            if (s[i] == '0') {
                evenZero--;
            } else {
                evenOne--;
            }

            swap(oddZero, evenZero);
            swap(oddOne, evenOne);
            if ((n - 1) % 2 == 1) {
                if (s[i] == '0')
                    oddZero++;
                else
                    oddOne++;

            } else {
                if (s[i] == '0')
                    evenZero++;
                else
                    evenOne++;
            }
            
        }
        return ans;
    }
};