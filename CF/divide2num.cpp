class Solution {
public:
    int divide(int dividend, int divisor) {
        int quotient = 0;
        int num = divisor;
        int sign = 1;
        if(dividend == divisor)return 1;
        if(divisor == 1)return dividend;
        if(divisor == -1){
            if(dividend == INT_MIN){
                return INT_MAX;
            }
            else{
                return -1*dividend;
            }
        }
        if(dividend == INT_MIN){
            if(divisor > 0){
                quotient++;
                dividend += divisor;
            }
            else{
                quotient++;
                dividend -= divisor;    
            }
        }
        while(abs(dividend) >= abs(divisor)){
        num = divisor;
        int quo = 1;
        if(dividend > 0){
            if(divisor > 0){
                while(num < dividend - num){
                    num += num;
                    quo += quo;
                }
            }
            else{
                sign = -1;
                while(num > -1*dividend - num){
                    num += num;
                    quo += quo;
                }
            }
        }
        else{
            if(divisor > 0){
                sign = -1;
                while(num > -1*dividend - num){
                    num += num;
                    quo += quo;
                }
            }
            else{
                while(num > dividend - num){
                    num += num;
                    quo += quo;
                }
            }
        }
        if((dividend > 0 && num > 0) || (dividend < 0 && num < 0)) dividend -= num;
        if((dividend > 0 && num < 0) || (dividend < 0 && num > 0)) dividend += num;
        if(quotient > INT_MAX - quo) return INT_MAX;
        quotient += quo;
        }
        return quotient*sign;
    }
};
