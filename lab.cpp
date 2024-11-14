#include <string> 
#include <fstream>
#include <iostream>
#include <map>
using namespace std;


map<char, int> getRepeatLetters(string filePath) {
    map<char, int> letterFreq;
    char ch;

    ifstream fin(filePath);
    if (fin.is_open()) {
        while (fin.get(ch)) {
            ch = tolower(ch);
            if (isalpha(ch)) {
                letterFreq[ch]++;
            }
        }
    }
    else {
        cout << "Файл не был открыт." << '\n';
        return letterFreq;
    }
    fin.close();
    return letterFreq;
}


map<string, int> getRepeatDoubleLetters(string filePath) {
    map<string, int> doubleLetterFreq;
    char ch;
    char prevChar = '\0';

    ifstream fin(filePath);
    if (fin.is_open()) {
        while (fin.get(ch)) {
            ch = tolower(ch);

            if (isalpha(ch)) {
                if (prevChar != '\0') {
                    string doubleLetter = string(1, prevChar) + ch;
                    doubleLetterFreq[doubleLetter]++;
                }
                prevChar = ch;
            }
            else {
                prevChar = '\0';
            }
        }
    }
    else {
        cout << "Файл не быт открыт." << '\n';
        return doubleLetterFreq;
    }
    return doubleLetterFreq;
}


int main() {
    string filePath = "lab.txt";
    setlocale(LC_ALL, "ru");

    map<char, int> letterFreq = getRepeatLetters(filePath);
    for (auto pair : letterFreq) {
        cout << "Буква: " << pair.first << " Частота: " << pair.second << '\n';
    }

    map<string, int> doubleLetterFreq = getRepeatDoubleLetters(filePath);
    for (auto pair : doubleLetterFreq) {
        cout << "Сочетание: " << pair.first << " Частота: " << pair.second << '\n';
    }

    return 0;
}