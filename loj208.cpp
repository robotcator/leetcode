#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int len = word.size();
    }

    // Returns if the word is in the trie.
    bool search(string word) {

    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {

    }

private:
    TrieNode* root;
};

int main(){
    return 0;
}
