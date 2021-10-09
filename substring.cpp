#include <vector>
#include <cstdlib>
#include <string>
#include <unordered_map>


using namespace std;

class Solution {

public:
    
    string **initDict() {
        string **new_dict = (string **)malloc(sizeof(string *)*27);
        for (unsigned i = 0; i < 27; i++) {
            new_dict[i] = NULL;
        }
        return new_dict;
    }

    string *lookupWord(string s, unsigned ix, string **words_d) {

        unsigned jx = 0;
        string **sub_d = words_d;

        while (ix - jx < s.size()) {
            unsigned kx = s[ix + jx] - 'a';
            if (sub_d[kx] != NULL) {
                sub_d = (string **)sub_d[kx];
            } else if (sub_d[26] != NULL) {
                return sub_d[26];
            } else {
                return NULL;
            }
            jx += 1;
        }

        if (sub_d[26] != NULL) {
            return sub_d[26];
        } else {
            return NULL;
        }

    }
    
    vector<int> findSubstring(string s, vector<string>& words) {

        if (words.size() == 0) {
            return vector<int>();
        }

        if (words[0].size() == 0) {
            return vector<int>();
        }
        
        string **words_d = initDict();
        unordered_map<string, int> word_to_count;
        
        for (unsigned i = 0; i < words.size(); i++) {

            string **sub_d = words_d;
            for (unsigned j = 0; j < words[i].size(); j++) {
                char k = words[i][j] - 'a';
                if (sub_d[k] == NULL) {
                    sub_d[k] = (string *)initDict();
                }
                sub_d = (string **)sub_d[k];
            }
            sub_d[26] = new string(words[i]);

            auto x = word_to_count.find(words[i]);
            if (x == word_to_count.end()) {
                word_to_count.insert({words[i], 1});
            } else {
                x->second++;
            }

        }

        vector<int> matches;

        for (unsigned ix = 0; ix < s.size() - words.size()*words[0].size(); ix++) {
            string *matched_word = lookupWord(s, ix, words_d);
            if (matched_word != NULL) {
                unordered_map<string, int> matched_words = { { *matched_word, 1} };
                unsigned jx = ix + words[0].size();
                bool is_continue = false;
                for (unsigned kx = 0; kx < words.size()-1; kx++) {
                    matched_word = lookupWord(s, jx, words_d);
                    if (matched_word != NULL) {
                        auto x = matched_words.find(*matched_word);
                        if (x == word_to_count.end()) {
                            matched_words.insert({*matched_word, 1});
                        } else {
                            x->second++;
                        }
                    } else {
                        is_continue = true;
                        break;
                    }
                }
                if (is_continue) {
                    continue;
                }
                if (matched_words == word_to_count) {
                    matches.push_back(ix);
                }
            }
        }

        return matches;

    }
};
