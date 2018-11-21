class Solution {
public:
    string convert(string s, int numRows) {
        int size_s = s.size();
        string output = "";
        int k, j;
        if (numRows <= 1) {
            return s;
        } 
        
        j = 0;
        while (2 * j * (numRows - 1) < size_s) {
            output.push_back(s[2 * j * (numRows - 1) ]);
            j ++;
        }
            
        for (k = 1; k <= numRows - 2; k++) {
            
            if (k < size_s) {
               output.push_back(s[k]);
            } else {
               return output;
            }
                
            j = 1;
            while (1) {
               if ((2 * j *(numRows -1) -k) < size_s) {
                output.push_back(s[2 * j * (numRows -1 ) - k]);
               } else {
                   break;
               }
                
               if ((2 * j *(numRows -1) + k) < size_s) {
                    output.push_back(s[2 * j * (numRows -1 ) + k]);
               } else {
                   break;
               }
                j ++;
            } /* while 1 */
        } // for
        
        j = 0;
        while ((2 * j + 1)*(numRows - 1) < size_s) {
            output.push_back(s[(2 * j + 1)* (numRows - 1) ]);
            j ++;
        }
        
        return output;
    } 
};
