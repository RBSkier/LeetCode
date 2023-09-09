typedef struct stack{
    int data[1000];
    int top;
}Stack;

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    Stack stack = {.top = -1};
    int i = 0, j = 0;
    while(i < poppedSize){
        if(stack.top == -1){
            stack.data[++stack.top] = pushed[j++];
            continue;
        }else{
            if(stack.data[stack.top] == popped[i]){
                stack.top--;
                i++;
            }else{
                if(j < pushedSize){
                    stack.data[++stack.top] = pushed[j++];
                    continue;
                }
                return false;
            }
        }
    }

    return true;
}
// popped中第一个出栈的整数肯定是一入栈就出栈，所以可以先模拟到该元素的入栈和立刻出栈。第二个出栈如此类推。
// 算法：
// 辅助栈（pushed）记录待入栈序列，

// 主栈(stack)入栈判断过程：
// ·当主栈为空时辅助栈pop，并在主栈push，
// ·当主栈不为空时，先看校验数组(popped)的当前元素是否是主栈第一个元素。
//     ·是的话主栈pop出，校验数组的当前元素下移。进行下一次入栈判断。
//     ·不是的话，从辅助栈中pop并在主栈push
// 当辅助栈空了以后：
//     ·就在主栈直接验证是否能按照剩余校验数组的顺序一样逐一pop出。如果检验数组遍历完毕，则校验通过，否则不通过。










