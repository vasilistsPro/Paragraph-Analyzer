#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class MyParagraph {
private:
    vector<string> sentences;
    vector<vector<string>> words;
    int sentences_count;

public:
    MyParagraph(string text) {
        // Split the input text into sentences
        size_t start = 0, end = text.find(". ");
        while (end != string::npos) {
            sentences.push_back(text.substr(start, end - start + 1));
            start = end + 2;
            end = text.find(". ", start);
        }
        sentences.push_back(text.substr(start));

        // Count the number of sentences
        sentences_count = sentences.size();

        // Split each sentence into words
        for (const string& sentence : sentences) {
            vector<string> sentence_words;
            size_t word_start = 0, word_end = sentence.find(' ');
            while (word_end != string::npos) {
                sentence_words.push_back(sentence.substr(word_start, word_end - word_start));
                word_start = word_end + 1;
                word_end = sentence.find(' ', word_start);
            }
            sentence_words.push_back(sentence.substr(word_start));
            words.push_back(sentence_words);
        }
    }

    void sentenceCount() {
        cout << "Number of sentences: " << sentences_count << endl;
    }

    void wordsPerSentence() {
        for (int i = 0; i < sentences_count; ++i) {
            cout << "Number of words in sentence " << i + 1 << ": " << words[i].size() << endl;
        }
    }

    void sortedWordsPerSentence() {
        for (int i = 0; i < sentences_count; ++i) {
            vector<string> sorted_words = words[i];
            sort(sorted_words.begin(), sorted_words.end());
            cout << "Sorted words in sentence " << i + 1 << ": ";
            for (const string& word : sorted_words) {
                cout << word << " ";
            }
            cout << endl;
        }
    }

    void vowelsAndConsonantsPerSentence() {
        for (int i = 0; i < sentences_count; ++i) {
            int vowels = 0, consonants = 0;
            for (const string& word : words[i]) {
                for (char ch : word) {
                    if (tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' ||
                        tolower(ch) == 'o' || tolower(ch) == 'u') {
                        vowels++;
                    }
                    else if (isalpha(ch)) {
                        consonants++;
                    }
                }
            }
            cout << "Sentence " << i + 1 << ": Vowels=" << vowels << ", Consonants=" << consonants << endl;
        }
    }
};

int main() {
    string paragraphText = "The mathematical study of magic squares typically deals with their construction, classification, and enumeration. Although completely general methods for producing all the magic squares of all orders do not exist, historically three general techniques have been discovered: by bordering method, by making composite magic squares, and by adding two preliminary squares. There are also more specific strategies like the continuous enumeration method that reproduces specific patterns. Magic squares are generally classified according to their order n as: odd if n is odd, evenly even also referred to as doubly even if n is a multiple of 4, oddly even also known as singly ev if n is any other even number. This classification is based on different techniques required to construct odd, evenly even, and oddly even squares. Beside this, depending on further properties, magic squares are also classified as associative magic squares, pandiagonal magic squares, most-perfect magic squares, and so on. More challengingly, attempts have also been made to classify all the magic squares of a given order as transformations of a smaller set of squares. Except for n ≤ 5, the enumeration of higher order magic squares is still an open challenge. The enumeration of most-perfect magic squares of any order was only accomplished in the late 20th century. ";
    MyParagraph myParagraph(paragraphText);

    myParagraph.sentenceCount();
    myParagraph.wordsPerSentence();
    myParagraph.sortedWordsPerSentence();
    myParagraph.vowelsAndConsonantsPerSentence();

    return 0;
}
