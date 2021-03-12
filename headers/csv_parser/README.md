# CSV PARSER
A c++ header which takes in csv files with a specific delimiter and then parses it.

<br>

## How to use it?
- include the file `parser.hpp` in your code.
```cpp
#include "parser.hpp"
```
- declare an object of the class `csv`
```cpp
csv obj;
```
- call the function as needed using the object.

<br>

## Functions supported
 ### 1. get_line
```cpp
std::string get_line(std::ifstream &file, int line)
```
Arguments: 
 - file: the input file
 - line: nth line which needs to be returned

Returns: The nth line in string format

### 2. parse_string
```cpp
std::vector<std::string> parse_string(std::string str, char delimiter = ',')
```
Arguments: 
 - str: a single line which needs to be parsed
 - delimiter: The character used for parsing

Returns: The line parsed and stored into a vector

### 3. parse_file
```cpp
std::vector<std::vector<std::string>> parse_file(std::ifstream &file, char delimiter = ',')
```
Arguments: 
 - file: the input file to be parsed
 - delimiter: The character used for parsing

Returns: vector of vector of strings which has the parsed file stored in a column major format. eg. the first line(header) would be stored in `v[0][i]` and the ith line would be stored in `v[i][j]`

### 4. print_line
```cpp
void print_line(std::string str, char input_delim = ',', char output_delim = '\t')
```
Arguments: 
 - str: the input string to be parsed and printed
 - input_delim: The character used for parsing
 - output_delim: the character which needs to be printed as a delimiter in the output

### 5. print_file
```cpp
void print_file(std::ifstream &file, char input_delim = ',', char output_delim = '\t')
```
Arguments: 
 - file: the input file to be parsed and printed
 - input_delim: The character used for parsing
 - output_delim: the character which needs to be printed as a delimiter in the output
<br/><br/>
## Examples
- Compile and execute the file `main.cpp`