/*Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.*/

------------------------------------------------------------------------------------------------------

/*생각해야할거 : hash map 사용. map 두개 만들어서 한개는 pattern의 알파벳 횟수 저장, 하나는 str의 단어들 출현횟수 저장
for loop으로 돌아댕기면서 map 업데이트. 만약 갯수가 맞지 않다 = str 의 단어가 맞지 않은 알파벳에 대응되어있는 상황 = 틀렸다고 return 
*/

class Solution {
public:
   
    bool wordPattern(string pattern, string str) {
        unordered_map<char,int> character;
        unordered_map<string,int> words;
        istringstream ss(str);
        string word;
        int i;
        int size=pattern.size();
        for(word; ss>>word;i++)
        {
            if(i==size||character[pattern[i]]!=words[word]) return false;
            character[pattern[i]]=words[word]=i+1;
        }
        return i==size;
    }
};
