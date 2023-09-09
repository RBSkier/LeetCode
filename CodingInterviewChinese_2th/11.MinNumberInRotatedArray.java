class Solution {
    public int minArray(int[] numbers) {
        int low = 0, high = numbers.length-1;
        while(low<high){
            int privot = low + (high - low)/2;
            if(numbers[privot] > numbers[high]){
                low = privot + 1;
            }else if(numbers[privot] < numbers[high]){
                high = privot;
            }else{
                high--;
            }
        }
        return numbers[low];
    }
}