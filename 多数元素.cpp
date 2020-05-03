/*
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
*/

int majorityElement(vector<int>& nums) {
    int limit=nums.size()/2;
    map<int, int> count;
    map<int, int>::iterator it;
    for(int i=0; i<nums.size(); i++){
        it=count.find(nums[i]);
        if(it==count.end()){
            count.insert(pair<int, int>(nums[i], 1));
        }else{
            it->second++;
        }
    }
    it=count.begin();
    while(it!=count.end()){
        if(it->second>limit)
            return it->first;
        it++;
    }
    return 0;
}

/*
思路比较简单，重点在于如何运用map解决问题。主要是map中iterator的用法，这个迭代器相当于指针，可以方便地对map中元素进行操作。
*/
