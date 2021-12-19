#include <fstream>
#include <string>
#include <iostream>
#include "lexer.cpp"
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
    f.open(fName);

    string txt = readFile2(fName);

    auto lexed = lexer(txt);
    printVec(lexed);
    auto parsed = parse(lexed);

}