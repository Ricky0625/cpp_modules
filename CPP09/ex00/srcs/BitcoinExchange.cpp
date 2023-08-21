/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:35:57 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/21 17:22:30 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// default constructor
BitcoinExchange::BitcoinExchange() {}

// copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    (void)other;
}

// assignment operator (overload)
BitcoinExchange    &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    (void)other;
    return *this;
}

// destructor
BitcoinExchange::~BitcoinExchange() {}

// date utils
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int year, int month, int day) {
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;
    
    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return day <= 29;
    return day <= daysInMonth[month];
}

// general utils
bool onlyHasOneOccurrence(const std::string &str, char target)
{
    return (str.find_first_of(target) == str.find_last_of(target));
}

static void extractDate(const std::string &date, int &year, int &month, int &day)
{
    std::istringstream dateStream(date);
    char dash = '-';

    dateStream >> year >> dash >> month >> dash >> day;
}

time_t  toEpochTime(const std::string &dateStr)
{
    int year;
    int month;
    int day;
    
    extractDate(dateStr, year, month, day);
    std::tm timeInfo = {};
    timeInfo.tm_year = year - 1900;
    timeInfo.tm_mon = month - 1; // (0-based)
    timeInfo.tm_mday = day;
    return std::mktime(&timeInfo);
}

// format utils
bool isValidDateFormat(const std::string &date)
{
    int year;
    int month;
    int day;

    extractDate(date, year, month, day);
    return isValidDate(year, month, day);
}

// check if the value is in INT format
bool isIntFormat(const std::string &value)
{   
    for (std::string::const_iterator it = value.begin(); it != value.end(); it++)
    {
        // if it's not digit
        if (!isdigit(*it))
            return false;
    }
    return true;
}

// check if the value is in FLOAT format
bool isFloatFormat(const std::string &value)
{
    if (!onlyHasOneOccurrence(value, '.'))
        return false;
    for (std::string::const_iterator it = value.begin(); it != value.end(); it++)
    {
        if (*it == '.')
            continue;
        if (!isdigit(*it))
            return false;
    }
    return true;
}

/**
 * @attention since this function will be used when storing data into database,
 *            it should not check if the value is within 0 to 1000.
*/
bool isValidValueFormat(const std::string &value)
{
    if (value[0] == '+' || value[0] == '-')
        return false;
    return (isIntFormat(value) || isFloatFormat(value));
}

/**
 * Pre-checking:
 * 1. Check if the argument count is 2 [DONE]
 * 2. Check if the file exists and can read (data.csv & input file) [DONE]
*/

/**
 * Checking for each line:
 * 1. Check each line of the input file
 *      a. Check if it's following the format (?) "date | value"
 *      b. Date should follow this format: Year-Month-Day
 *      c. Value should follow this format: 0 - 1000, can accept float or int
*/

/**
 * Flow
 * 1. Pre-checking [DONE]
 * 2. Store all the info of data.csv into a map (assuming the data will always follow the format, as it's given by the subject) [DONE]
 * 3. Read the input file, for each line:
 *      a. do checking for each line
 *      b. find that record in the map
 *          i. if doesn't exists, use the closest date, use the lower date not the upper one
 *      c. print the updated record. value from input file * value in record
*/

/**
 * Error handling
 * 1. For pre-checking, the program should end if any of the criteria does not pass [DONE]
 * 2. For line checking, the program should just print an error message and continue until all the contents of the file has been read
*/

/**
 * First, check if BTC_DATABASE exists and can read.
 * Then, check if <file> exists and can read.
*/
static void checkFile(std::ifstream &database, std::ifstream &readFile, const std::string &file)
{
    // for ifstream::open, the function prototype is like this:
    // void open(const char *filename, ios_base::openmode mode = ios_base::in);
    // it already has a default opening mode, so no need to specify will work as well.
    database.open(BTC_DATABASE);
    readFile.open(file.c_str());
    if (!database.is_open())
        throw BitcoinExchange::BTCDatabaseDoesNotExist();
    if (!readFile.is_open())
        throw BitcoinExchange::BTCErrorWhenOpenFile();
}

void storeDataToDatabase(const std::string &str, MapType &dataMap)
{
    const char delimeter = ',';
    size_t  delimeter_pos = str.find(delimeter);
    std::string key = str.substr(0, delimeter_pos);
    std::string value = str.substr(delimeter_pos + 1, str.size());
    if (!(isValidDateFormat(key) && isValidValueFormat(value)))
        throw BitcoinExchange::BTCErrorWhileParsingDatabaseFile();
    
    time_t keyAsEpochTime = toEpochTime(key);
    float valueAsFloat = strtof(value.c_str(), NULL);
    
    std::pair<time_t, float> keyValuePair;
    keyValuePair = std::make_pair(keyAsEpochTime, valueAsFloat);
    dataMap.insert(keyValuePair);
}

/**
 * Make this function generic
*/
static void getLineFromFile(std::ifstream &file, MapType &dataMap, void (*func)(const std::string &str, MapType &datamap), e_type readType = DATABASE)
{
    std::string line;
    
    // if read from database, skip the first line
    if (readType == DATABASE)
        std::getline(file, line);
    while (std::getline(file, line))
        func(line, dataMap);
    // close the file after reading
    file.close();
}

void BitcoinExchange::bitcoinExchange(const std::string &file)
{
    std::ifstream database;
    std::ifstream readFile;
    MapType dataMap;

    checkFile(database, readFile, file);
    getLineFromFile(database, dataMap, storeDataToDatabase);
    for (MapType::iterator it = dataMap.begin(); it != dataMap.end(); it++)
    {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
}

// Exception
const char *BitcoinExchange::BTCDatabaseDoesNotExist::what() const throw()
{
    return "[ERROR]: Failed to open database!";
}

const char *BitcoinExchange::BTCErrorWhenOpenFile::what() const throw()
{
    return "[ERROR]: Failed to open file!";
}

const char *BitcoinExchange::BTCErrorWhileParsingDatabaseFile::what() const throw()
{
    return "[ERROR]: Failed to parse database data!";
}
