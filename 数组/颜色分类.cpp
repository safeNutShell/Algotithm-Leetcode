/*
给定一个包含红色、白色和蓝色，一共n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
注意:
不能使用代码库中的排序函数来解决这道题。
示例:
输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
*/

void sortColors(vector<int>& nums) {
    if(nums.size()==1||nums.size()==0) return;
    int leftPtr=0, rightPtr=nums.size()-1;
    while(nums[leftPtr]==0 && leftPtr<nums.size()-1) leftPtr++;
    while(nums[rightPtr]==2 && rightPtr>0) rightPtr--;
    int ptr=leftPtr;
    while(ptr<=rightPtr){
        if(nums[ptr]==0){
            nums[ptr]=nums[leftPtr];
            nums[leftPtr]=0;
            leftPtr++;
            ptr++;
        }
        else if(nums[ptr]==2){
            nums[ptr]=nums[rightPtr];
            nums[rightPtr]=2;
            rightPtr--;
        }
        else{
            ptr++;
        }
    }
}

/*
遍历数组，把0全部往最左放，把2全部往最右放，1自动就位。
关键是每次交换后各个指针怎么移动。
遇到0，2后，leftPtr和rightPtr分别自增、自减没有问题，遇到1后ptr自增进一位也没有问题。
关键是不能每次交换过元素之后ptr都自增，ptr要留在最左部和leftPtr一起自增，从而在范围缩小得过程中对左部做扫尾工作。
*/
