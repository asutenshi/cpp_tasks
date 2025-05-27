#include <iostream>

#include "suffixTree.h"

using namespace std;

int main(int argc, char **argv)
{
    SuffixTree suffTree;
    char operation_mode;

    if (argc < 2 || argc > 3) {
        throw runtime_error("Usage: ./suffTree <c|f> [input_file.txt]");
    }

    string mode_arg = argv[1];
    if (mode_arg.length() != 1 || (mode_arg[0] != 'c' && mode_arg[0] != 'f')) {
        throw runtime_error("Invalid mode. Mode must be 'c' or 'f'.\nUsage: ./suffTree <c|f> [input_file.txt]");
    }
    operation_mode = mode_arg[0];

    if (argc == 3) {
        string file_path = argv[2];
        ifstream in(file_path);
        if (!in.is_open()) {
            throw std::runtime_error("Cannot open file: " + file_path);
        }
        suffTree = SuffixTree(in);
        cout << suffTree << endl;
    } else {
        string input;
        cout << "Write string for build a suffixTree: ";
        cin >> input;
        suffTree = SuffixTree(input + '$');
    }

    string buff;
    while (true) {
        cout << "Write string to find or compare in suffixTree (q$ for quit): ";
        cin >> buff;
        if (buff == "q$") {
            break;
        }
        if (operation_mode == 'f') {
            if (suffTree.contain(buff)) {
                cout << "SuffixTree contain string " << (buff.size() > 10 ? buff.substr(0, 10) + "..." : buff) << endl;
            } else {
                cout << "SuffixTree NOT contain string " << (buff.size() > 10 ? buff.substr(0, 10) + "..." : buff) << endl;
            }
        } else {
            cout << "Compare = " << suffTree.compare(buff) << std::endl;
        }
    }
    return 0;
}