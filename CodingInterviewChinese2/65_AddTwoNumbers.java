class Solution {
    public int add(int a, int b) {
        int num1 = a;
        int num2 = b;
        int sum;
        int carry;
        do
        {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
        }
        while(num2 != 0);

        return num1;
    }
}