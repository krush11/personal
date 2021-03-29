#ifndef PARSER_H
#define PARSER_H

#pragma once

#include <vector>
#include <string>
#include <iostream>

class csv
{
public:
    size_t parse(std::string data, size_t size)
    {
        int position = data.find('\n');
        if(position == std::string::npos)
            return 0;
        else
            return position+1;
    }

    std::vector<std::string> parse_columns(std::string data)
    {
        int position = data.find('\n');
        std::string buffer = data.substr(0, position);
        std::vector<std::string> parsed_line;
        while (!buffer.empty())
        {
            int delimiter_pos = buffer.find(',');
            std::string word = buffer.substr(0, delimiter_pos);

            if (delimiter_pos == -1)
            {
                parsed_line.push_back(word);
                break;
            }
            else
            {
                buffer = buffer.substr(delimiter_pos + 1);
                parsed_line.push_back(word);
            }
        }
        return parsed_line;
    }

    std::string remove_prefix(std::string data, size_t size)
    {
        int position = data.find('\n');
        data = data.substr(position+1);
        return data;
    }
};

#endif
