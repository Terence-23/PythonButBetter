#include <fstream>
#include <string>
#include <iostream>
#include "parser.cpp"

string readFile2(const string &fileName)
{
    ifstream ifs(fileName.c_str(), ios::in | ios::binary | ios::ate);

    ifstream::pos_type fileSize = ifs.tellg();
    ifs.seekg(0, ios::beg);

    vector<char> bytes(fileSize);
    ifs.read(bytes.data(), fileSize);

    return string(bytes.data(), fileSize);
}

void printVec(const vector<token> vec)
{
    for (auto i : vec)
    {
        cout << "id: " << i.id << " text: " << i.text << '\n';
    }
}

int main()
{
    ifstream f;
    string fName;
    cin >> fName;
    string txt;
    try
    {
        txt = readFile2(fName);
    }
    catch (std::exception &e)
    {
        cout << "Error while reading a file:\n"
             << e.what() << '\n';
        return 1;
    }
    vector<token> lexed;
    try
    {
        lexed = lexer(txt);
    }
    catch (std::invalid_argument &e)
    {
        cout << "error in lexer:\n"
             << e.what() << "\n";
        return 1;
    }
    printVec(lexed);
    TokenNode parsed;
    try
    {
        parsed = parse(lexed);
    }
    catch (std::invalid_argument &e)
    {
        cout << "Error while parsing into ATS:\n"
             << e.what() << "\n";
        return 1;
    }
    cout << "Done\n";
}