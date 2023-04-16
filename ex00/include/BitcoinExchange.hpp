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

        btcMap      getMap();
        void        setMap(btcMap map);
        double      getBiggestSmall(std::string val);
        std::string getBiggestDate ();
    private:
        btcMap  _prices;

};