class Solution {
public:
    string gcdOfStrings(string s, string t) {
        if (s + t != t + s) return "";

        int g = gcd(s.size(), t.size());
        return s.substr(0, g);
    }
};