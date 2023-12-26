#include <iostream>
#include <fstream>
#include "MyParagraph.h"
#include <string>

class MainProgramParagraph2 {
private:
    MyParagraph myParagraph; 

public:
    MainProgramParagraph2() : myParagraph("") {}  

    void menu() {
        int choice;
        do {
            std::cout << "Menu:" << std::endl;
            std::cout << "1. Inserting a paragraph from keyboard." << std::endl;
            std::cout << "2. Reading a paragraph from file." << std::endl;
            std::cout << "3. Presenting paragraph's processing results in console." << std::endl;
            std::cout << "4. Writing paragraph's processing results in file." << std::endl;
            std::cout << "5. Exit." << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                insertParagraphFromKeyboard();
                break;
            case 2:
                readParagraphFromFile();
                break;
            case 3:
                presentResultsInConsole();
                break;
            case 4:
                writeResultsInFile();
                break;
            case 5:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            }

        } while (choice != 5);
    }

    void insertParagraphFromKeyboard() {
        std::string paragraph;
        std::cout << "Enter a paragraph from keyboard: ";
        std::cin.ignore(); 
        std::getline(std::cin, paragraph);
        myParagraph = MyParagraph(paragraph); 
        std::cout << "Paragraph inserted successfully." << std::endl;
    }

    void readParagraphFromFile() {
        std::string filename;
        std::cout << "Enter the filename: ";
        std::cin >> filename;

        myParagraph.readParagraphFromFile(filename); 
    }

    void presentResultsInConsole() {
        myParagraph.presentResultsInConsole(); 
    }

    void writeResultsInFile() {
        std::string filename;
        std::cout << "Enter the filename to write results: ";
        std::cin >> filename;

        myParagraph.writeResultsInFile(filename); 
    }
};

int main() {
    MainProgramParagraph2 program;
    program.menu();

    return 0;
}
