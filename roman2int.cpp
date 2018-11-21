class Solution {
public:
    int romanToInt(string s) {
        map <char, int> roman2int;
        int sLen = s.length();
        int lastValue, curValue = 0;
        if (sLen == 0) {
            return 0;
        }
        int value = 0;
        roman2int['I'] = 1;
        roman2int['V'] = 5;
        roman2int['X'] = 10;
        roman2int['L'] = 50;
        roman2int['C'] = 100;
        roman2int['D'] = 500;
        roman2int['M'] = 1000;
        
        value = roman2int[s[sLen-1]];
        lastValue = value;
        sLen --;
        while (sLen > 0) {
            curValue = roman2int[s[sLen-1]];
            if ( curValue >= lastValue) {
                value += curValue;
            } else {
                value -= curValue;
            }
            lastValue = curValue;
            sLen--;
        }
        
        return value;
        
        
    }
};
