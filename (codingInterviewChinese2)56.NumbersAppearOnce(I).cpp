class Solution {
private:
    int findFirstBitIs1(int num){
        int bit = 0;
        while((num & 1) == 0 && bit < sizeof(int) * 8)
        {
            num = num >> 1;
            ++bit;
        }
        return bit;
    }
    bool bitIs1(int num, int bit){
        num = num >> bit;
        return num & 1;
    }
public:
    vector<int> singleNumbers(vector<int>& nums) {
        //robutst
        if(nums.empty())
            return vector<int>();

        int xorNum = 0;
        for(int num: nums)
            xorNum ^= num;
        int bit = findFirstBitIs1(xorNum); //找到第一个是1的bit

        int xor1 = 0, xor2 = 0;
        for(int num: nums){
            if(bitIs1(num, bit) == true)    //根据某个bit作为特征值将两个不同的数分到不同的组，顺便而且顺便把重复的数都会分到同一组
                xor1 ^= num;
            else
                xor2 ^= num;
        }
        return vector<int>{xor1, xor2};
    }
};