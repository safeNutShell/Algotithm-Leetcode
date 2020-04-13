/*给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。*/

public String longestPalindrome(String s) {
    if(s==null||s.length()==0) return "";
    int p=0, q=0;
    for(int i=0;i<s.length();i++){
        int len1 = helper(s, i, i);
        int len2 = helper(s, i, i+1);
        int len = Math.max(len1, len2);
        if(len>q-p){
            p=i-(len-1)/2;
            q=i+(len/2);
        }
    }
    return s.substring(p,q+1);
}

public int helper(String s, int leftCore, int rightCore){
    int L=leftCore, R=rightCore;
    while(L>=0 && R<s.length() && s.charAt(L)==s.charAt(R)){
        L--;
        R++;
    }
    return R-L-1;
}

/*首先观察回文串的特殊之处，即存在一个core，自其向两端扩散。那么只要遍历可能的core，并判断对应的回文串的长度，更新下标就得到了最后的最长回文串*/
