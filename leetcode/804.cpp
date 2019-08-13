class Solution {
vector<string> dict = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> sst;
        for (auto it = words.begin(); it!=words.end(); it++) {
            string result="";
            for (int i=0; i<(*it).length(); i++)
                result+=( dict[(*it)[i]-'a']);
            sst.insert(result);
        }
        return sst.size();
    }
};
