class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned long results = 0;
        unsigned long cnt = 0;
        int result_signed = ((dividend > 0) ^ (divisor > 0))?(-1):1;
        unsigned long abs_dividend = abs((long)dividend);
        unsigned long abs_divisor = abs((long)divisor);
        unsigned  long tmp, temp_dividend;
        
        if(!divisor)   return INT_MAX;
        if (abs_dividend < abs_divisor) return 0;    
        
        tmp = abs_divisor;
        while ((tmp<<cnt) <= abs_dividend ) {
            cnt++;
        }
        cnt --;
        temp_dividend = abs_dividend;
        tmp = abs_divisor;
        
        for (int i = cnt; i >= 0; i --){
            if ((tmp << i) <= temp_dividend){
                results += 1 << i; 
                temp_dividend -= (tmp << i);
            }
        }
          
        if (result_signed > 0) {
            return (results > INT_MAX) ? INT_MAX : results;
        } else {
            return (-results < INT_MIN) ? INT_MIN : (-results);
        }
        
    }
};
