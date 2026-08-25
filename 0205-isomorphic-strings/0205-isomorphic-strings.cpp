class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        int sToT[256] = {0};
        int tToS[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            char b = t[i];

            if (sToT[a] != 0 && sToT[a] != b)
                return false;

            if (tToS[b] != 0 && tToS[b] != a)
                return false;

            sToT[a] = b;
            tToS[b] = a;
        }

        return true;
    }
};