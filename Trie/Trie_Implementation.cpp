/**
 * Title     : Trie Implementation (Insert & Search)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode *child[ALPHABET_SIZE];
    int endOfString; // Counts the no. of string ending at a node
    // bool endOfString; // Checks if any string ends at a node
};

TrieNode* createTrieNode() {

    TrieNode *newTrieNode = new TrieNode();

    for (int i = 0; i < ALPHABET_SIZE; ++i)
        newTrieNode -> child[i] = NULL;

    newTrieNode -> endOfString = 0;

    return newTrieNode;
}

// Insert a string into the trie

void addString(TrieNode *root, string str) {

    TrieNode *curr = root;

    for (int i = 0; i < str.length(); ++i) {

        int index = str[i] - 'a';

        if (curr -> child[index] == NULL)
            curr -> child[index] = createTrieNode();

        curr = curr -> child[index];
    }

    ++curr -> endOfString;
}
// Time Complexity: O(L), where 'L' is length of the string to be inserted

// Search for a string in the trie

int searchString(TrieNode *root, string str) {

    TrieNode *curr = root;

    for (int i = 0; i < str.length(); ++i) {

        int index = str[i] - 'a';

        if (curr -> child[index] == NULL)
            return 0;

        curr = curr -> child[index];
    }

    return curr -> endOfString;
}
// Time Complexity: O(L), where 'L' is length of the string to be searched

int main() {

    TrieNode *root = createTrieNode();

    string allStrings[] = {"the", "a", "there", "answer", "the", "by", "the", "their"};

    int n = sizeof(allStrings) / sizeof(allStrings[0]);

    for (int i = 0; i < n; ++i) {
        addString(root, allStrings[i]);
    }

    string words[] = {"the", "these"};

    int m = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < m; ++i) {

        int frequency = searchString(root, words[i]);

        if (frequency != 0)
            cout << "The word '" << words[i] << "' is present " << frequency << " times" << '\n';
        else
            cout << "The word '" << words[i] << "' is not present" << '\n';
    }

    return 0;
}
