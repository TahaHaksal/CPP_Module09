#include "../include/BitcoinExchange.hpp"

double safe_atof(const char* str) {
    char* endptr;
    double val = std::strtod(str, &endptr);
    if (*endptr != '\0') {
        std::stringstream ss;
        ss << "Invalid input string: " << str;
        throw std::invalid_argument(ss.str());
    }
    return val;
}

void capitalize(std::string& str) {
    std::locale loc;
    for (size_t i = 0; i < str.length(); i++) {
        str[i] = std::toupper(str[i], loc);
    }
}

btc::BitcoinExchange(std::string fileName)
{
    //Construct
    std::ifstream   file(fileName.c_str());
    std::string     line;
    if (!file.good())
    {
        std::cerr << "Couldn't open the file: " << fileName << std::endl;
        exit(1);
    }
    bool    firstLine = true;
    while (std::getline(file, line))
    {
        if (firstLine)
        {
            std::string date = line.substr(0, line.find_first_of(','));
            std::string value = line.substr(line.find_first_of(',') + 1, line.size());
            std::cout << date << "--" << value << std::endl;
            capitalize(date);
            capitalize(value);
            if (date != "DATE" || value != "EXCHANGE_RATE")
            {
                std::cerr << "Given files format isn't what is as expected: 'date|exchange_rate'";
                exit(1);
            }
            firstLine = false;
            continue;
        }
        std::string date = line.substr(0, line.find_first_of(','));
        std::string price = line.substr(line.find_first_of(',') + 1);
        double num;
        try {
            num = safe_atof(price.c_str());
        } catch (const std::invalid_argument& e) {
            std::cerr << "There was an error while parsing the csv file" << std::endl;
        }
        _prices[date] = num;
    }
    for (btcMap::iterator it = )
}

btc::~BitcoinExchange()
{
    //Destruct
}

btcMap  btc::getMap()
{
    return _prices;
}

void    btc::setMap(btcMap map)
{
    _prices = map;
}
/**
 * @brief takes a date value pair and finds the closest small date to it
 * 
 * @param val a date value pair
 * @return int returns the closest dates price value
 */
double     btc::getBiggestSmall(std::string val)
{
    std::string tmp = "";
    for (btcMap::iterator it = _prices.begin(); it != _prices.end(); it++)
    {
        if (it->first < val && (tmp == "" || tmp < it->first))
            tmp = it->first;
    }
    double closestPrice = (_prices.find(tmp) != _prices.end()) ? _prices[tmp] : 0.0;
    return closestPrice;
}

std::string btc::getBiggestDate ()
{
    std::string tmp = "";
    for (btcMap::iterator it = _prices.begin(); it != _prices.end(); it++)
    {
        if (it->first > tmp)
            tmp = it->first;
    }
    return tmp;
}