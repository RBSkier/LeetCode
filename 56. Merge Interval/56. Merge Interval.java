class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (int[] a, int[] b) -> a[0] - b[0]);

        List<int[]> output = new ArrayList<>();
        output.add(intervals[0]);    //初始化输出列表
        for(int i = 1; i < intervals.length; i++){
            //如果左值在上一个区间范围内
            int last = output.size() - 1;
            if(intervals[i][0] >= output.get(last)[0] && intervals[i][0] <= output.get(last)[1]) {
                if(intervals[i][1] > output.get(last)[1])
                    output.get(last)[1] = intervals[i][1];
            }else{
                output.add(intervals[i]);
            }
        }

        return output.toArray(new int[output.size()][]);
    }
}
