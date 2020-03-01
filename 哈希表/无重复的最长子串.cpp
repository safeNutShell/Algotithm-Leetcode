//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

  int lengthOfLongestSubstring(string s) {
      set<char> a;
      int res=0, i=0, j=0;
      int n=s.size();
      while(i<n&&j<n){
          if(a.count(s[j])==0){
              a.insert(s[j++]);
              res=max(res, (int)a.size());
          }
          else{
              a.erase(s[i++]);
          }
      }
      return res;
  }
  
  /*
  这题最简单的想法是遍历，以i为下标遍历字符串，并计算不同起点的i对应的最长子串。很明显，这样效率不高。
  改进的方法是采用滑动窗口，窗口的前端用j向前伸展，一旦s[j]重复则将窗口尾部i也向前伸展，这样使i的递增不那么死板。
  进一步的，一旦s[j]重复，i实际可以直接跳过与其发生重复的s[j']，但是这样存储字符的数据结构就要改变，要用pair同时存储字符和下标
  */
