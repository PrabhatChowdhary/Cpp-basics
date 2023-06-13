#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <unordered_map>

using namespace std;

vector<long> countAnagramSentences(vector<string> words, vector<string> sentences) {
    vector<long> result;
    
    unordered_map<string, int> wordCount;
    for (string& w : words) {
        sort(w.begin(), w.end());
        wordCount[w]++;
    }
    
    for (string& s : sentences) {
        istringstream iss(s);
        vector<string> Sen_words = vector<string>(istream_iterator<string>(iss), istream_iterator<string>());
        
        long count = 1;

        for (string& w : Sen_words) {
            sort(w.begin(), w.end());
            
            if (wordCount[w]>0) 
                count *= wordCount[w];
        }
        
        result.push_back(count);
    }

    return result;
}

int main() {
    vector<string> words = {"listen", "silent", "pot", "top"};
    vector<string> sentences = { "silent is listen", "silent is listen pot", "dog"};
    
    vector<long> counts = countAnagramSentences(words, sentences);
    
    for (long i = 0; i < counts.size(); i++) {
        cout << counts[i] << endl;
    }
    
    return 0;
}
