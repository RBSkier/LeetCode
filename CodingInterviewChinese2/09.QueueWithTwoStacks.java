class CQueue {
    private Stack<Integer> stack_in, stack_out;

    public CQueue() {
        stack_in = new Stack<Integer>();
        stack_out = new Stack<Integer>();
    }

    public void appendTail(int value) {
        stack_in.push(value);
    }

    public int deleteHead() {
        if(stack_out.size() == 0){
            if(stack_in.size() == 0){
                return -1;
            }else{
                while(stack_in.size() != 0){
                    stack_out.push(stack_in.pop());
                }
                
            }
        }
        return stack_out.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */