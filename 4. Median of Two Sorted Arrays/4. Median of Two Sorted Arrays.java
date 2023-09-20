class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        //make sure nums1 is the shorter array.
	int m = nums1.length, n = nums2.length;
        if(nums1.length > nums2.length)
            return findMedianSortedArrays(nums2, nums1);   
        
        int start = 0, end = m;
        int median1 = 0, median2 = 0;
        while(start <= end){
            int i = (start + end) / 2;
            int j = (m + n + 1) / 2 - i;
            //if i  == 0 or j == 0, means the left part of nums1/nums2 is empty.
            int leftMax1 = i == 0 ? Integer.MIN_VALUE : nums1[i - 1];
            int rightMin2 = j == n ? Integer.MAX_VALUE : nums2[j];
            int rightMin1 = i == m ? Integer.MAX_VALUE : nums1[i];
            int leftMax2 = j == 0 ? Integer.MIN_VALUE : nums2[j - 1];
            
            if(leftMax1 <= rightMin2){
                median1 = Math.max(leftMax1, leftMax2);
                median2 = Math.min(rightMin1, rightMin2);
                start = i + 1;
            }else{
                end = i - 1;
            }
        }
        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
}
