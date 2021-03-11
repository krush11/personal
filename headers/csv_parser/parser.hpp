using namespace std;

class csv
{
public:
    vector<vector<string>> parse(ifstream &file, char delimiter = ',', bool print = false)
    {
        string str;
        vector<vector<string>> parsed_data;
        while (getline(file, str))
        {
            vector<string> parsed_line;
            while (!str.empty())
            {
                int delimiter_pos = str.find(delimiter);
                string word = str.substr(0, delimiter_pos);
                // cout << word << " ";

                if (delimiter_pos == -1)
                {
                    parsed_line.push_back(word);
                    break;
                }
                else
                {
                    str = str.substr(delimiter_pos + 1);
                    // cout << str << endl;
                    parsed_line.push_back(word);
                }
            }
            parsed_data.push_back(parsed_line);
        }

        if (print)
        {
            cout << "Size of csv file: " << parsed_data.size() << endl;
            for (int i = 0; i < parsed_data.size(); i++)
            {
                for (int j = 0; j < parsed_data[i].size(); j++)
                    cout << parsed_data[i][j] << "  ";
                cout << endl;
            }
        }

        return parsed_data;
    }
};