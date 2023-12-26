#include "MyParagraph.h"
#include <iostream>
#include <algorithm>
#include <cctype>

MyParagraph::MyParagraph(std::string text) {
    
    size_t start = 0, end = text.find(". ");
    while (end != std::string::npos) {
        sentences.push_back(text.substr(start, end - start + 1));
        start = end + 2;
        end = text.find(". ", start);
    }
    sentences.push_back(text.substr(start));

    sentencesCount = sentences.size();

    
    for (const std::string& sentence : sentences) {
        std::vector<std::string> sentence_words;
        size_t word_start = 0, word_end = sentence.find(' ');
        while (word_end != std::string::npos) {
            sentence_words.push_back(sentence.substr(word_start, word_end - word_start));
            word_start = word_end + 1;
            word_end = sentence.find(' ', word_start);
        }
        sentence_words.push_back(sentence.substr(word_start));
        words.push_back(sentence_words);
    }
}

void MyParagraph::writeResultsInFile(const std::string& filename) {
    std::ofstream outFile(filename);

    if (outFile.is_open()) {
        sentenceCountToFile(outFile);
        wordsPerSentenceToFile(outFile);
        sortedWordsPerSentenceToFile(outFile);
        vowelsAndConsonantsPerSentenceToFile(outFile);

        outFile.close();
        std::cout << "Results written to " << filename << "." << std::endl;
    }
    else {
        std::cout << "Error opening file " << filename << " for writing." << std::endl;
    }
}

void MyParagraph::readParagraphFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string paragraph((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        sentences.clear();
        words.clear();
        sentencesCount = 0;
        size_t start = 0, end = paragraph.find(". ");
        while (end != std::string::npos) {
            sentences.push_back(paragraph.substr(start, end - start + 1));
            start = end + 2;
            end = paragraph.find(". ", start);
        }
        sentences.push_back(paragraph.substr(start));

        
        sentencesCount = sentences.size();

        
        for (const std::string& sentence : sentences) {
            std::vector<std::string> sentence_words;
            size_t word_start = 0, word_end = sentence.find(' ');
            while (word_end != std::string::npos) {
                sentence_words.push_back(sentence.substr(word_start, word_end - word_start));
                word_start = word_end + 1;
                word_end = sentence.find(' ', word_start);
            }
            sentence_words.push_back(sentence.substr(word_start));
            words.push_back(sentence_words);
        }

        std::cout << "Paragraph read successfully from file." << std::endl;
    }
    else {
        std::cout << "Error opening file. Please make sure the file exists." << std::endl;
    }
}

void MyParagraph::sentenceCount() {
    sentencesCount = sentences.size();
    std::cout << "Sentence Count: " << sentencesCount << std::endl;
}

void MyParagraph::wordsPerSentence() {
    for (size_t i = 0; i < sentences.size(); ++i) {
        std::cout << "Words in Sentence " << i + 1 << ": " << words[i].size() << std::endl;
    }
}


void MyParagraph::sortedWordsPerSentence() {
    for (size_t i = 0; i < sentences.size(); ++i) {
        std::vector<std::string> sortedWords = words[i];
        std::sort(sortedWords.begin(), sortedWords.end());

        std::cout << "Sorted Words in Sentence " << i + 1 << ": ";
        for (const auto& word : sortedWords) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
}

void MyParagraph::presentResultsInConsole() {
    sentenceCount();
    wordsPerSentence();
    sortedWordsPerSentence();
    vowelsAndConsonantsPerSentence();
}


void MyParagraph::vowelsAndConsonantsPerSentence() {
    for (size_t i = 0; i < sentences.size(); ++i) {
        int vowels = 0;
        int consonants = 0;

        for (const auto& word : words[i]) {
            for (char c : word) {
                if (std::isalpha(c)) {
                    char lowercaseChar = std::tolower(c);
                    if (lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' ||
                        lowercaseChar == 'o' || lowercaseChar == 'u') {
                        ++vowels;
                    }
                    else {
                        ++consonants;
                    }
                }
            }
        }

        std::cout << "Vowels and Consonants in Sentence " << i + 1 << ": ";
        std::cout << "Vowels: " << vowels << ", Consonants: " << consonants << std::endl;
    }
}


void MyParagraph::sentenceCountToFile(std::ofstream& outFile) {
    outFile << "Sentence Count: " << sentencesCount << std::endl;
}


void MyParagraph::wordsPerSentenceToFile(std::ofstream& outFile) {
    for (size_t i = 0; i < sentences.size(); ++i) {
        outFile << "Words in Sentence " << i + 1 << ": " << words[i].size() << std::endl;
    }
}


void MyParagraph::sortedWordsPerSentenceToFile(std::ofstream& outFile) {
    for (size_t i = 0; i < sentences.size(); ++i) {
        std::vector<std::string> sortedWords = words[i];
        std::sort(sortedWords.begin(), sortedWords.end());

        outFile << "Sorted Words in Sentence " << i + 1 << ": ";
        for (const auto& word : sortedWords) {
            outFile << word << " ";
        }
        outFile << std::endl;
    }
}


void MyParagraph::vowelsAndConsonantsPerSentenceToFile(std::ofstream& outFile) {
    for (size_t i = 0; i < sentences.size(); ++i) {
        int vowels = 0;
        int consonants = 0;

        for (const auto& word : words[i]) {
            for (char c : word) {
                if (std::isalpha(c)) {
                    char lowercaseChar = std::tolower(c);
                    if (lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' ||
                        lowercaseChar == 'o' || lowercaseChar == 'u') {
                        ++vowels;
                    }
                    else {
                        ++consonants;
                    }
                }
            }
        }

        outFile << "Vowels and Consonants in Sentence " << i + 1 << ": ";
        outFile << "Vowels: " << vowels << ", Consonants: " << consonants << std::endl;
    }
}
