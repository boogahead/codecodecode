class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int size = 0, hehe;
        for (string i : words) hehe = i.size(), size = max(size, hehe);
        if (words.size() != size) return false;
        for (int i = 0; i < words.size(); i++) for (int j = 0; j < words[i].size(); j++) if (words[i][j] != words[j][i]) return false;
        return true;
    }
};
