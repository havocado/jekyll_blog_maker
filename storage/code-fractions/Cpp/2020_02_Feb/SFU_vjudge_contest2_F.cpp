// Code NOT DONE!!

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class WordNode {
public:
    WordNode* parent;
    bool isEndOfWord;
    string fullWord;
    string word;
    bool tabSet;
    WordNode* tabWord;
    vector<pair<WordNode*, int>> edges;
    WordNode(const WordNode*& parent, const bool*& isEndOfWord,
            const string& fullWord, const string& word,
            const bool& tabSet, const WordNode*& tabWord) : parent(parent),
        isEndOfWord(isEndOfWord), fullWord(fullWord),
        word(word), tabSet(tabSet), tabWord(tabWord) { }
}

int main() {
    int m, n;
    cin >> m >> n;

    // Initializing Graph
    vector<WordNode> starters;
    starters.reserve(26);
    for (int i = 0; i < 26; i++) {
        WordNode word(nullptr, false, 'a'+i, 'a'+i, false, "");
        starters.push_back(word);
    }

    // Construction
    for (int i = 0; i < m; i++)


    return 0;
}
