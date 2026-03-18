#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Playfair {
    char matrix[5][5];

    void findPosition(char c, int &r, int &c_pos) {
        if (c == 'J') c = 'I';
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                if (matrix[i][j] == c) {
                    r = i; c_pos = j;
                    return;
                }
    }

public:
    Playfair(string key) {
        string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
        string temp = "";
        for (char c : key) if (isalpha(c)) temp += toupper(c);
        temp += alphabet;

        string finalKey = "";
        for (char c : temp) {
            if (c == 'J') c = 'I';
            if (finalKey.find(c) == string::npos) finalKey += c;
        }

        for (int i = 0; i < 25; i++)
            matrix[i / 5][i % 5] = finalKey[i];
    }

    string encrypt(string text) {
        string prepared = "";
        for (char c : text) if (isalpha(c)) prepared += toupper(c);

        string processed = "";
        for (int i = 0; i < prepared.length(); i += 2) {
            processed += prepared[i];
            if (i + 1 < prepared.length()) {
                if (prepared[i] == prepared[i + 1]) {
                    processed += 'X';
                    i--;
                } else {
                    processed += prepared[i + 1];
                }
            } else {
                processed += 'X';
            }
        }

        string result = "";
        for (int i = 0; i < processed.length(); i += 2) {
            int r1, c1, r2, c2;
            findPosition(processed[i], r1, c1);
            findPosition(processed[i + 1], r2, c2);

            if (r1 == r2) {
                result += matrix[r1][(c1 + 1) % 5];
                result += matrix[r2][(c2 + 1) % 5];
            } else if (c1 == c2) {
                result += matrix[(r1 + 1) % 5][c1];
                result += matrix[(r2 + 1) % 5][c2];
            } else {
                result += matrix[r1][c2];
                result += matrix[r2][c1];
            }
        }
        return result;
    }
};

int main() {
    string key = "MONARCHY";
    string text = "DO YOU LIKE TO STUDY CRYPTOGRAPHY COURSE";

    Playfair pf(key);
    cout << "Keyword: " << key << endl;
    cout << "Plaintext: " << text << endl;
    cout << "Ciphertext: " << pf.encrypt(text) << endl;

    return 0;
}