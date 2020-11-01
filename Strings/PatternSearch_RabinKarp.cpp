/**
 * Title     : Search for a pattern in a text (Rabin-Karp Algorithm)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 9;
const int prime = 31;

long long createHash(string text, int end, vector<int> prime_powers) {

    long long hash = 0;

    for (int i = 0; i <= end; ++i)
        hash += (text[i] * prime_powers[i]) % MOD;

    return hash;
}

long long recalculateHash(string text, int oldIndex, int newIndex, long long oldHash, int patternLen, vector<int> prime_powers) {

    long long newHash = oldHash - text[oldIndex];
    newHash /= prime;
    newHash += (text[newIndex] * prime_powers[patternLen - 1]) % MOD;

    return newHash;
}

bool checkEqual(string text, int startText, int endText, string pattern, int startPattern, int endPattern) {

    if ((endText - startText) != (endPattern - startPattern))
        return false;

    while ((startText <= endText) && (startPattern <= endPattern)) {

        if (text[startText] != pattern[startPattern])
            return false;

        ++startText;
        ++startPattern;
    }

    return true;
}

vector<int> patternSearch(string text, string pattern) {

    int m = pattern.length();
    int n = text.length();

    vector<int> prime_powers(m);
    prime_powers[0] = 1;

    for (int i = 1; i < m; ++i)
        prime_powers[i] = (prime_powers[i - 1] * prime) % MOD;

    long long patternHash = createHash(pattern, m - 1, prime_powers);
    long long textHash = createHash(text, m - 1, prime_powers);

    vector<int> index;

    for (int i = 1; i <= n - m + 1; ++i) {

        if (patternHash == textHash && checkEqual(text, i - 1, i + m - 2, pattern, 0, m - 1))
            index.emplace_back(i - 1);

        if (i < n - m + 1)
            textHash = recalculateHash(text, i - 1, i + m - 1, textHash, m, prime_powers);
    }

    return index;
}

// A more concise variant:
/*
vector<int> patternSearch(string text, string pattern) {

    int n = text.length();
    int m = pattern.length();

    vector<long long> prime_powers(max(n, m));
    prime_powers[0] = 1;

    for (int i = 1; i < (int)prime_powers.size(); ++i) {
        prime_powers[i] = (prime_powers[i - 1] * prime) % MOD;
    }

    vector<long long> hash_text(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        hash_text[i + 1] = (hash_text[i] + (text[i] - 'a' + 1) * prime_powers[i]) % MOD;
    }

    long long hash_pattern = 0;

    for (int i = 0; i < m; ++i) {
        hash_pattern = (hash_pattern + (pattern[i] - 'a' + 1) * prime_powers[i]) % MOD;
    }

    vector <int> index;

    for (int i = 0; i < n - m + 1; ++i) {
        long long curr_hash = (hash_text[i + m] + MOD - hash_text[i]) % MOD;
        if (curr_hash == hash_pattern * prime_powers[i] % MOD)
            index.emplace_back(i);
    }

    return index;
}
*/

int main() {

    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    vector<int> index;

    index = patternSearch(text, pattern);

    if (!index.size()) {
        cout << "Pattern not found in text";
    }
    else {
        cout << "Pattern found at index: ";
        for (auto i : index)
            cout << i << ' ';
    }

    return 0;
}

/*
 ~ Time Complexity  : O(n + m) -> Best case & Average case
                    : O(n * m) -> Worst case
   where 'n' is the text length and 'm' is the pattern length
*/
