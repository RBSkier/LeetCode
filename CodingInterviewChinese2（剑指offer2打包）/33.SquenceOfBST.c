
              
bool verifyCore(int* postorder, int postorderSize){
    if(postorderSize < 3){
        return true;
    }

    int root = postorder[postorderSize - 1];
    int right_subtree_index = -1;
    for(int i = 0; i < postorderSize - 1; i++){
        if(postorder[i] > root){
            right_subtree_index = i;
            for(int j = right_subtree_index; j <  postorderSize - 1; j++){
                if(postorder[j] <= root){
                    return false;
                }
            }
            break;
        }
    }
    
    if(right_subtree_index == -1 || right_subtree_index == 0){  //说明只有左子树或者只有右子树
        return verifyCore(postorder, postorderSize - 1);

    }else{
        int left_subtree_size = right_subtree_index;
        int right_subtree_size = postorderSize - 1 - right_subtree_index;
        return verifyCore(postorder, left_subtree_size) && verifyCore(postorder + right_subtree_index, right_subtree_size);
    }

}

bool verifyPostorder(int* postorder, int postorderSize){
    if(postorder == NULL){
        return true;
    }
    if(postorderSize < 0){
        return false;
    }

    return verifyCore(postorder, postorderSize);
}
   



