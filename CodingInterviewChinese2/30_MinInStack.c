typedef struct {
    int top;
    int data[20000];
    int min[20000];
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* pMinStack = malloc(sizeof(MinStack));
    pMinStack->top = -1;
    return pMinStack;
}

void minStackPush(MinStack* obj, int x) {
    int minVal;
    if(obj->top == -1){
        minVal = x;
    }else{
        if(x < obj->min[obj->top]){
            minVal = x;
        }else{
            minVal = obj->min[obj->top];
        }
    }
    ++obj->top;
    obj->data[obj->top] = x;
    obj->min[obj->top] = minVal;
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top];
}

int minStackMin(MinStack* obj) {
    return obj->min[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj);
}