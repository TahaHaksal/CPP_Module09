#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include <stdint.h>
#include <iomanip>

typedef class BitcoinExchange btc;
typedef std::map<std::string, double> btcMap;

void capitalize(std::string& str);
double safe_atof(const char* str);

class BitcoinExchange
{
    public:
        BitcoinExchange(std::string fileName);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& copy);

        btcMap      getMap();
        double      getBiggestSmall(std::string val);
        std::string getBiggestDate ();
        btcMap  _prices;

};