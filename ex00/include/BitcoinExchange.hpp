#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include <iomanip>

typedef class BitcoinExchange btc;
typedef std::map<std::string, double> btcMap;

class BitcoinExchange
{
    public:
        BitcoinExchange(std::string fileName);
        ~BitcoinExchange();

        btcMap  getMap();
        void    setMap(btcMap map);
        int     getBiggestSmall(btcMap val);
    private:
        btcMap  _prices;

};