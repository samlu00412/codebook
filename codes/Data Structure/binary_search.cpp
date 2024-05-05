LL BS(LL left,LL right){
    if(left+1 >= right)//break condition
        return -1;
    LL mid = (left+right)/2;
    if(arr[mid] == target)
        return mid;
    else if(arr[mid] < target){
        left = mid+1;
        BS(left,right);
    }
    else if(arr[mid] > target){
        right = mid;
        BS(left,right);
    }
}