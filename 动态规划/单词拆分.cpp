/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
*/

bool wordBreak(string s, vector<string>& wordDict) {
    set<string> dict;
    for (int i = 0; i < wordDict.size(); i++) {
        dict.insert(wordDict[i]);
    }
    bool* dp = new bool[s.size() + 1];
    for (int i = 0; i < s.size()+1; i++) {
        dp[i] = false;
    }
    dp[0] = true;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j <= i; j++) {
            if (dp[j] && dict.count(s.substr(j, i - j + 1))==1) {
                dp[i+1] = true;
                break;
            }
        }
    }
    bool res = dp[s.size()];
    delete[]dp;
    return res;
}

/*
此解的思想是动态规划，dp首先要解决的就是寻找一个通项，即当前的结果需要怎样的前提。
在此题中，如果整个字符串都出现在字典中，那么必然可以分割成一个字典单词+一个同样符合条件的字符串。
下标i遍历成哥符串，下标j遍历子字符串。
注意new的格式，取子串、取长度等对string的操作。
*/
