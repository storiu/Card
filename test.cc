#include "iostream"
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


bool checkLuhn(const string& cardNo)
{
    if (cardNo[0] != '4' || (cardNo.length() != 13 && cardNo.length() != 16)) {
        return false;
    }
    int nDigits = cardNo.length();
    int nSum = 0, isSecond = false;
    for (int i = nDigits - 1; i >= 0; i--) {

        int d = cardNo[i] - '0';

        if (isSecond == true)
            d = d * 2;

        nSum += d / 10;
        nSum += d % 10;

        isSecond = !isSecond;
    }
    return (nSum % 10 == 0);
}

bool isIncludeFullName(string name)
{
    stringstream ss(name);
    string word;
    int i = 0;
    while (ss >> word) {
        i++;
    }
    if(i > 1) return true;
    else return false;
}

bool isValid(string number) 
{  
    return checkLuhn(number);
}

bool iszero(int i) {
    if (i<10) {
        return true;
    }
    return false;
}

int main()
{
    string name = "";
    string cardnum = "";
    int cardexpiremonth = 0;
    int cardexpireyear = 0;
    string transactionnum = "";
    int date = 0;
    int month = 0;
    int year = 0;
    string time = "";
    double Amount = 0;

    while (cin) {
        getline(cin, name);
        if (name == "") {
            exit(0);
        }

        cin >> cardnum;
        cin >> cardexpiremonth;
        cin >> cardexpireyear;
        cin >> transactionnum;
        cin >> date;
        cin >> month;
        cin >> year;
        cin >> time;
        cin >> Amount;
        cin.ignore();

        cout << setprecision(2)<<fixed;

         cout << transactionnum << " " << (iszero(date)? "0" : "") << date << "/" << 
             (iszero(month)? "0" : "") << month << "/"
                << year << " " << time.insert(2, ":") << " " << "$" << Amount <<
                " " << "(" << cardnum << ", " << name << (isIncludeFullName(name) ? "": " ") << ", " <<
                (iszero(cardexpiremonth)? "0" : "") << cardexpiremonth << "/" << cardexpireyear << ") " <<
                (isValid(cardnum) && isIncludeFullName(name) ? "valid" : "invalid") <<'\n';

    }
    return 0;
}
