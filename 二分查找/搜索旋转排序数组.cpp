/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。
*/

int search(vector<int>& nums, int target) {
    int n=nums.size();
    if(n==0) return -1;
    if(n==1) return nums[0]==target?0:-1;
    int l=0, r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]>=nums[0]){//这里取等于号是因为“有序”的定义，即使是“3，1，2”也认为nums[0]左边是有序的
            if(target>=nums[0]&&target<nums[mid])
                r=mid-1;
            else
                l=mid+1;
        }else{
            if(target>nums[mid]&&target<=nums[n-1])
                l=mid+1;
            else
                r=mid-1;
        }
    }
    return -1;
}

/*
由于数组变化，在使用二分查找时要对边界情况进行分类。要抓住乱序后其实是左右两个有序数组，关键就是判断每次的mid的左右数组是无序还是有序。
利用有序的部分进行判断。
*/
