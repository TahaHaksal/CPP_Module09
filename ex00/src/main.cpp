#include "../include/BitcoinExchange.hpp"

std::string trim(const std::string& str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isspace(*it)) {
        ++it;
    }

    std::string::const_reverse_iterator rit = str.rbegin();
    while (rit.base() != it && std::isspace(*rit)) {
        ++rit;
    }

    return std::string(it, rit.base());
}

int main(int ac, char** av) {
	std::cout.setf(std::ios::fixed);
	// std::cout.precision(5);
	btc a("data.csv");
	if (ac != 2)
	{
		std::cout << "Wrong amount of parameters: ./btc exampleFileName\n";
		exit(1);
	}
	std::fstream file(av[1]);
	if (!file.good())
	{
		std::cout << "Can't open the file with the name " << av[1] << std::endl;
		exit(1);
	}
	std::string line;
	std::string	btcDate = "2009-01-03";
	bool		firstLine = true;
	while (std::getline(file, line))
	{
		std::string::size_type pipePos = line.find_first_of('|');
		if (firstLine)
		{
			std::string date = line.substr(0, pipePos);
            std::string value = line.substr(pipePos + 1);
            capitalize(date);
            capitalize(value);
            if (date != "DATE " || value != " VALUE")
            {
                std::cerr << "Given files format isn't as expected: 'date|value'\n";
                exit(1);
            }
            firstLine = false;
			continue;
		}
		
		//DATE
		std::string date = trim(line.substr(0, pipePos));
		if (date < btcDate)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue ;
		}
        //DATE

		double amount;
		if (pipePos != std::string::npos)
		{
			amount = safe_atof(line.substr(pipePos + 1).c_str());
			if (amount < 0) {std::cout << "Error: not a positive number.\n"; continue;}
		}
		else
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue ;
		}

		// std::cout << "*" << (a._prices.find(date) != a._prices.end()) << "*\n";
		double price = (a._prices.find(date) != a._prices.end()) ? a._prices.find(date)->second : a.getBiggestSmall(date);
		if (price == 0 || amount == 0)
			std::cout << date << " => " << amount << " = " << price << std::endl;
		else if (INT32_MAX / price <= amount)
			std::cout << "Error: too large a number\n";
		else
			std::cout << date << " => " << amount << " = " << amount * price << std::endl;
	}
}
