#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
#include "parser.hpp"

using namespace std;

int main()
{
    ifstream file;
    file.open("sample.csv");
    csv obj;
    obj.parse(file, ',', true);
}
