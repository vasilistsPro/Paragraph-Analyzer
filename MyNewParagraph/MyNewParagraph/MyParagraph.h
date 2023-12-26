#ifndef MYPARAGRAPH_H
#define MYPARAGRAPH_H

#include <vector>
#include <string>
#include <fstream>

class MyParagraph {
private:
    std::vector<std::string> sentences;
    std::vector<std::vector<std::string>> words;
    int sentencesCount;

public:
    MyParagraph(std::string text);
    void writeResultsInFile(const std::string& filename);
    void readParagraphFromFile(const std::string& filename);
    void sentenceCount();
    void wordsPerSentence();
    void sortedWordsPerSentence();
    void presentResultsInConsole();
    void vowelsAndConsonantsPerSentence();
    void sentenceCountToFile(std::ofstream& outFile);
    void wordsPerSentenceToFile(std::ofstream& outFile);
    void sortedWordsPerSentenceToFile(std::ofstream& outFile);
    void vowelsAndConsonantsPerSentenceToFile(std::ofstream& outFile);
};

#endif // MYPARAGRAPH_H
