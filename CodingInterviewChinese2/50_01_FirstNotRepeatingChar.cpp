class Solution {
public:
//哈希思想
    char firstUniqChar(string s) {
       int* arr = new int[26]{0};//确定只包含小写字母
       for(int i = 0;i < s.size(); i++)
       {
           ++arr[s[i]-'a']; //s[i]-min
       } 
       //输出映射表
    //    for(int i =0;i<26;i++)
    //    {
    //        cout << arr[i] << " "; 
    //    }
    //    cout << endl;

       for(int i =0;i<s.size();i++)
       {
           if(arr[s[i]-'a'] == 1)
           {
               return s[i];
           }
       }
       return ' ';
    }
};