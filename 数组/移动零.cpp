/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
*/

void moveZeroes(vector<int>& nums) {
    int ZeroCount=0;
    int cur=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]!=0){
            nums[cur]=nums[i];
            cur++;
        }else{
            ZeroCount++;
        }
    }
    if(ZeroCount!=0){
        for(int j=0; j<ZeroCount; j++){
            nums[cur+j]=0;
        }
    }
}

/*
尽量减少遍历次数；合理使用下标指针进行辅助
*/
