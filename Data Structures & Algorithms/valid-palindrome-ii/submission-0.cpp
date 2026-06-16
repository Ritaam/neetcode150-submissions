class Solution {
bool isPallindrome(string s) {
    int lp = 0;
    int rp = s.size() - 1;
    while(lp < rp) {
        if(s[lp] != s[rp]) {
            return false;
        }
        lp++;
        rp--;
    }
    return true;
}

public:
    bool validPalindrome(string s) {
        if(isPallindrome(s)) {
            return true;
        }

        for(int i = 0; i < s.size(); i++) {
            string newS = s.substr(0,i) + s.substr(i + 1);
            if(isPallindrome(newS)) {
                return true;
            }
        }
        return false;
    }
};