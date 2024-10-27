#include <iostream>
#include <unordered_map>
#include <map>
#include <sstream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

void countWordsUnordered(const string& text) {
    unordered_map<string, int> wordCount;
    istringstream stream(text);
    string word;

    while (stream >> word) {
        wordCount[word]++;
    }

    for (const auto& entry : wordCount) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

void countWordsOrdered(const string& text) {
    map<string, int> wordCount;
    istringstream stream(text);
    string word;

    while (stream >> word) {
        wordCount[word]++;
    }

    for (const auto& entry : wordCount) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

int main() {
    string text = "this is a sample text this text is a test for word frequency counting";

    auto start = high_resolution_clock::now();
    countWordsUnordered(text);
    auto end = high_resolution_clock::now();
    auto durationUnordered = duration_cast<microseconds>(end - start).count();
    cout << "Time taken by unordered map: " << durationUnordered << " microseconds" << endl;

    start = high_resolution_clock::now();
    countWordsOrdered(text);
    end = high_resolution_clock::now();
    auto durationOrdered = duration_cast<microseconds>(end - start).count();
    cout << "Time taken by ordered map: " << durationOrdered << " microseconds" << endl;

    return 0;
}
