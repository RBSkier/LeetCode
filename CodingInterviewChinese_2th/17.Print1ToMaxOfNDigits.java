class Solution {

    int[] ret;
    char[] number;
    int n;

    public int[] printNumbers(int n) {
        double max = Math.pow(10,n) - 1;
        ret = new int[(int)max];
        number = new char[n];
        this.n = n;
        dfs(0);

        return ret;
    }

    public void dfs(int index){
        if(index == n){
            String str = new String(number);
            int no = Integer.parseInt(str);
            if(no != 0){
                ret[no - 1] = no;
            }
            return;
        }

        for(int i = 0; i <= 9; i++){
            number[index] = (char)(i + '0');
            dfs(index + 1);
        }
    }

}