/**
 * Title     : Count the number of words in a Trie
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode *child[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode* createTrieNode() {

    TrieNode *newTrieNode = new TrieNode();

    newTrieNode -> isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        newTrieNode -> child[i] = NULL;
    }

    return newTrieNode;
}

void insertWord(TrieNode *root, string word) {

        TrieNode *curr = root;

        for (int i = 0; i < word.length(); ++i) {

            int index = word[i] - 'a';

            if (curr -> child[index] == NULL)
                curr -> child[index] = createTrieNode();

            curr = curr -> child[index];
        }

        curr -> isEndOfWord = true;
}

int countWordsInTrie(TrieNode *root) {

    int cnt = 0;

    if (root -> isEndOfWord == true)
        ++cnt;

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (root -> child[i] != NULL)
            cnt += countWordsInTrie(root -> child[i]);
    }

    return cnt;
}

int main() {

    TrieNode *root = createTrieNode();

    string words[] = {"sea", "see", "seat", "seam", "seal", "sat", "saw", "same"};

    int n = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < n; ++i) {
        insertWord(root, words[i]);
    }

    int wordCount = countWordsInTrie(root);
    cout << "Number of words in the trie: " << wordCount;

    return 0;
}

/*
 ~ Time Complexity   : O(length of each word * ALPHABET_SIZE * total number of words)
 ~ Space Complexity  : O(length of the longest word)
*/
