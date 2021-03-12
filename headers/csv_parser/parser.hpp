#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <fstream>
#include <string>

class csv
{
public:
    std::string get_line(std::ifstream &file, int line)
    {
        std::string s;
        file.seekg(0, std::ios::beg);
        for (int i = 0; i <= line; i++)
            getline(file, s);

        return s;
    }

    std::vector<std::string> parse_string(std::string str, char delimiter = ',')
    {
        std::vector<std::string> parsed_line;
        while (!str.empty())
        {
            int delimiter_pos = str.find(delimiter);
            std::string word = str.substr(0, delimiter_pos);

            if (delimiter_pos == -1)
            {
                parsed_line.push_back(word);
                break;
            }
            else
            {
                str = str.substr(delimiter_pos + 1);
                parsed_line.push_back(word);
            }
        }
        return parsed_line;
    }

    std::vector<std::vector<std::string>> parse_file(std::ifstream &file, char delimiter = ',')
    {
        std::string str;
        std::vector<std::vector<std::string>> parsed_data;
        while (getline(file, str))
        {
            std::vector<std::string> parsed_line = parse_string(str);
            parsed_data.push_back(parsed_line);
        }

        return parsed_data;
    }

    void print_line(std::string str, char input_delim = ',', char output_delim = '\t')
    {
        std::vector<std::string> parsed_line = parse_string(str, input_delim);

        for (int i = 0; i < parsed_line.size(); i++)
            std::cout << parsed_line[i] << output_delim;
    }

    void print_file(std::ifstream &file, char input_delim = ',', char output_delim = '\t')
    {
        file.seekg(0, std::ios::beg);
        std::vector<std::vector<std::string>> parsed_csv_data = parse_file(file, input_delim);

        for (int i = 0; i < parsed_csv_data.size(); i++)
        {
            for (int j = 0; j < parsed_csv_data[i].size(); j++)
                std::cout << parsed_csv_data[i][j] << output_delim;
            std::cout << std::endl;
        }
    }
};

#endif
