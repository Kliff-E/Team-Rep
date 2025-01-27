#include <iostream>
#include <regex>
#include <string>


using namespace std;

bool validateFormat(const string& datetime);


int main()
{
    string input;

    cout << "Enter date and time (YYYY-MM_DD HH:mm:ss): ";
    getline(cin, input);

    if(validateFormat(input))
    {
        cout << "The entered date and time is in the correct format." << endl;
    }
    else{
        cout << "The entered date and time is NOT in the corret format." << endl;
    }

    return 0;
}

bool validateFormat(const string &datetime)
{
    regex pattern(R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2})");

    return regex_match(datetime, pattern);
}