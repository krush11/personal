## CSV PARSER
A c++ header which takes in csv files with a specific delimiter and then parses it.

### How to use it?
- include the file `parser.hpp` in your code.
```cpp
#include "parser.hpp"
```
- declare an object of the class `csv`
```cpp
csv obj;
```
- call the function `parse()` using the object.
```cpp
vector<vector<string>> parse(ifstream &file, char delimiter = ',', bool print = false)
```

The function takes 3 arguments - a file, a char delimiter and bool to print the parsed data.
<br><br>

### Examples
- Compile and execute the file `main.cpp`