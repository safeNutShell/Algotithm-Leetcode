给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。

//解：
bool canJump(vector<int>& nums) {
    int pre=0,curr=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            pre=curr;
            curr=i;
            int tmp=curr-1;
            while(1){
                if(tmp<pre){
                    return false;
                }
                if(nums[tmp]<=curr-tmp){
                    tmp--;
                }
                else{
                    break;
                }
            }

        }
    }
    return true;
}
