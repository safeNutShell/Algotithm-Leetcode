/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

void mySort(vector<int>& nums, int l, int r) {
    for (int i = l; i <= r; i++) {
        int curMin = i;
        for (int j = i; j <= r; j++) {
            if (nums[j] < nums[curMin])
                curMin = j;
        }
        int tmp = nums[curMin];
        nums[curMin] = nums[i];
        nums[i] = tmp;
    }
}
    
 void nextPermutation(vector<int>& nums) {
    int size = nums.size();
    if(size==0) return;
    if(size==1) return;
    int ptr = size - 1;
    for (ptr; ptr >= 0; ptr--) {
        if (ptr == 0) break;
        if (nums[ptr - 1] < nums[ptr]) {
            ptr--;
            break;
        }
    }
    if (ptr == 0 && nums[ptr]>=nums[ptr+1]) {
        for (int i = 0; i < size / 2; i++) {
            int tmp = nums[i];
            nums[i] = nums[size - 1 - i];
            nums[size - 1 - i] = tmp;
        }
    }
    else {
        int target = ptr;
        for (int i = ptr + 1; i < size; i++) {
            if (nums[i] > nums[ptr]) target = i;
            if (nums[i] <= nums[ptr]) break;
        }
        int tmp = nums[ptr];
        nums[ptr] = nums[target];
        nums[target] = tmp;
        //从ptr+1到size-1做一次排序，小的放前面
        mySort(nums, ptr + 1, size - 1);
    }
}

/*
通过折线图的动态变化找出规律，即从尾部开始第一个下降的位置即为需要操作的数位，同时从本数位往后的数组也应进行排序。
排序算法应该优化。
*/
