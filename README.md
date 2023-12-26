# Paragraph-Analyzer

This C++ program is designed to analyze paragraphs, offering various statistics such as the number of sentences, the number of words per sentence, sorted words per sentence, and the count of vowels and consonants per sentence. The program consists of two parts, each implemented in separate classes.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Class Structure](#class-structure)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Paragraph Analyzer program is designed to process and analyze paragraphs, providing valuable insights into their structure and composition. The program is divided into two main parts:

1. **MyParagraph Class (Part 1):** 
   - Processes a paragraph provided as a string.
   - Computes statistics such as the number of sentences, words per sentence, sorted words per sentence, and vowels and consonants per sentence.
   - Supports both console output and writing results to a file.

2. **MainProgramParagraph2 Class (Part 2):**
   - Utilizes the MyParagraph class to interact with the user.
   - Implements a simple menu-driven interface for inserting paragraphs, reading paragraphs from files, presenting results in the console, writing results to files, and exiting the program.

## Features

- **Sentence Count:**
  - Counts the number of sentences in a paragraph.

- **Words per Sentence:**
  - Calculates the number of words in each sentence.

- **Sorted Words per Sentence:**
  - Presents the words in each sentence in sorted order.

- **Vowels and Consonants per Sentence:**
  - Counts the number of vowels and consonants in each sentence.

- **Paragraph Insertion:**
  - Accepts a paragraph from the keyboard.

- **Paragraph Reading:**
  - Reads a paragraph from a user-specified file.

- **Console Presentation:**
  - Displays processing results in the console.

- **File Output:**
  - Writes processing results to a user-specified file.

## Usage

To use the program, follow these steps:

1. Compile the C++ files using your preferred compiler.
2. Run the compiled executable.
3. Follow the menu options to insert a paragraph, read a paragraph from a file, present results in the console, write results to a file, or exit the program.

## Class Structure

### MyParagraph Class (Part 1)

#### Public Methods:
- `MyParagraph(std::string text)`: Constructor that processes a given paragraph.
- `writeResultsInFile(const std::string& filename)`: Writes processing results to a file.
- `readParagraphFromFile(const std::string& filename)`: Reads a paragraph from a file.
- `sentenceCount()`: Counts the number of sentences.
- `wordsPerSentence()`: Calculates the number of words in each sentence.
- `sortedWordsPerSentence()`: Presents the words in each sentence in sorted order.
- `vowelsAndConsonantsPerSentence()`: Counts the number of vowels and consonants in each sentence.
- `presentResultsInConsole()`: Displays processing results in the console.

### MainProgramParagraph2 Class (Part 2)

#### Public Methods:
- `MainProgramParagraph2()`: Constructor initializing MyParagraph with an empty paragraph.
- `menu()`: Displays a menu and handles user choices.
- `insertParagraphFromKeyboard()`: Accepts a paragraph from the keyboard.
- `readParagraphFromFile()`: Reads a paragraph from a file.
- `presentResultsInConsole()`: Displays processing results in the console.
- `writeResultsInFile()`: Writes processing results to a file.

## Example

```cpp
#include <iostream>
#include <fstream>
#include "MyParagraph.h"
#include "MainProgramParagraph2.h"
#include <string>

int main() {
    MainProgramParagraph2 program;
    program.menu();

    return 0;
}
