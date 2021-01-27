#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

/*
1. Check word is in list or not
2. start from begin word, find the distance to rest words.
3. If minimum dist is greater than number of other words, return 0
4. select one from rest
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        size_t numWords = wordList.size();
        std::vector<string>::iterator it = find(wordList.begin(), wordList.end(), endWord);
        if (it == wordList.end()) {
            return 0;
        }
        size_t endIndex = it - wordList.begin();

        return _shortWordLadderLengthHelper(beginWord, endWord, wordList, numWords, endIndex);

        if (numWords <= 26 * beginWord.length()) {
            return _longWordLadderLengthHelper(beginWord, endWord, wordList, numWords, endIndex);
        }
        else {
            return _shortWordLadderLengthHelper(beginWord, endWord, wordList, numWords, endIndex);

        }
    }
private:
    int _calDistance(string word_1, string word_2) {
        //Assume that size of two string is the same
        int dist = 0;
        for (size_t i = 0; i < word_1.size(); i++) {
            if (word_1[i] != word_2[i]) {
                dist += 1;
                if (dist > 1) { return false; }
            }
        }
        return dist;
    }

    int _shortWordLadderLengthHelper(string beginWord, string endWord, vector<string>& wordList, size_t numWords, size_t endIndex) {
        std::unordered_set<string> unvisited;
        for (std::vector<string>::iterator it = wordList.begin(); it != wordList.end(); ++it) {
            unvisited.insert(*it);
        }

        std::queue<string> q;
        q.push(beginWord);

        int depth = 0;
        while (!q.empty()) {
            size_t layer_width = q.size();
            depth += 1;

            for (size_t wordIndex = 0; wordIndex < layer_width; wordIndex++) {
                const string currentWord = q.front();
                q.pop();
                for (size_t i = 0; i < currentWord.size(); i++) {
                    string tempWord = currentWord;
                    for (char letter = 'a'; letter <= 'z'; letter++) {
                        tempWord[i] = letter;

                        if (currentWord == tempWord) continue;

                        if (endWord == tempWord) return depth + 1;

                        if (unvisited.end() != unvisited.find(tempWord)) {
                            q.push(tempWord);
                            unvisited.erase(tempWord);
                        }

                    }
                }
            }


        }
        return 0;
    }

    int _longWordLadderLengthHelper(string beginWord, string endWord, vector<string>& wordList, size_t numWords, size_t endIndex) {


        int distance = _calDistance(beginWord, endWord);
        if (1 == distance) {
            return 2;
        }
        else if (distance > numWords + 1) {
            return 0;
        }
        else {
            int *dist = new int[numWords];
            memset(dist, INT_MAX, sizeof(int)*numWords);
            bool *visit = new bool[numWords];
            memset(visit, false, sizeof(bool)*numWords);


            bool reachable = false;
            for (size_t arr_idx = 0; arr_idx < wordList.size(); arr_idx++) {
                if (1 == _calDistance(beginWord, wordList[arr_idx])) {
                    dist[arr_idx] = 1;
                    reachable = true;
                }
                else {
                    dist[arr_idx] = INT_MAX;
                }
            }

            if (reachable) {
                while (true) {
                    // TODO:
                    // 1. find min dist from unvisited point set
                    // 2. add to visited ps
                    // 3. update edge
                    size_t min_index = -1;
                    int min_value = INT_MAX;
                    for (size_t idx = 0; idx < numWords; idx++) {
                        if (!visit[idx] && INT_MAX != dist[idx]) {
                            if (min_index == -1 || dist[idx] < dist[min_index]) {
                                min_index = idx;
                            }
                        }
                    }

                    if (-1 == min_index || endIndex == min_index) {
                        break;
                    }
                    else {
                        visit[min_index] = true;
                        for (size_t idx = 0; idx < numWords; idx++) {
                            if (_calDistance(wordList[min_index], wordList[idx]) == 1 && dist[idx] > dist[min_index] + 1) {
                                dist[idx] = dist[min_index] + 1;
                            }
                        }
                    }
                }

            }

            if (INT_MAX != dist[endIndex]) {
                return dist[endIndex] + 1;
            }
            else {
                return 0;
            }
        }
    }
};

int main() {
    vector<string> image = { "hot","dot","dog","lot","log","cog" };
    string beginWord = "hit";
    string endWord = "cog";
    Solution s = Solution();
    int d = s.ladderLength(beginWord, endWord, image);
    std::cout<<d;
    system("pause");
    return 0;
}