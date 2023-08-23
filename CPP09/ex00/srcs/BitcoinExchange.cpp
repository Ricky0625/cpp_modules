/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:35:57 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/23 15:15:16 by wricky-t         ###   ########.fr       */
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
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    (void)other;
    return *this;
}

// destructor
BitcoinExchange::~BitcoinExchange() {}

// date utils
// check if the given year is a leap year
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// check if the given year, month and day forms a valid date
bool isValidDate(int year, int month, int day)
{
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return day <= 29;
    return day <= daysInMonth[month];
}

// general utils
// check if a character only appear once in the string
bool onlyHasOneOccurrence(const std::string &str, char target)
{
    return (str.find_first_of(target) == str.find_last_of(target));
}

// extract the date from a string into year, month and day
static bool extractDate(const std::string &date, int &year, int &month, int &day)
{
    std::istringstream dateStream(date);
    char dash1, dash2;

    dateStream >> year >> dash1 >> month >> dash2 >> day;
    if (dateStream.fail() || dash1 != '-' || dash2 != '-')
        return false;
    return true;
}

// convert date string into epoch time
time_t strToEpochTime(const std::string &dateStr)
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

// convert epoch time (time_t) to string
std::string epochTimeToStr(time_t epochTime)
{
    std::tm *timeInfo = std::localtime(&epochTime);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeInfo);

    return buffer;
}

// format utils
// check if the given date string is a valid date format
bool isValidDateFormat(const std::string &date)
{
    int year;
    int month;
    int day;

    if (!extractDate(date, year, month, day))
    {
        std::cout << "Invalid date format [DATABASE]: " BRED << date << RESET << std::endl;
        throw BitcoinExchange::BTCErrorWhileParsingDatabaseFile();
    }
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

static void extractKeyValue(const std::string &str, std::string &key, std::string &value, const std::string &delimeter, e_type readType = READFILE)
{
    if (str.empty() && readType == READFILE)
        throw BitcoinExchange::BTCEmptyLine();
    else if (str.empty() && readType == DATABASE)
        throw BitcoinExchange::BTCErrorWhileParsingDatabaseFile();

    size_t delimeter_pos = str.find(delimeter);

    if (delimeter_pos == std::string::npos)
        throw BitcoinExchange::BTCFailedToParseLine();

    key = str.substr(0, delimeter_pos);
    value = str.substr(delimeter_pos + delimeter.size(), str.size());

    if (key.empty() && readType == READFILE)
        throw BitcoinExchange::BTCNoDateGiven();
    else if (key.empty() && readType == DATABASE)
        throw BitcoinExchange::BTCErrorWhileParsingDatabaseFile();

    if (value.empty() && readType == READFILE)
        throw BitcoinExchange::BTCNoValueGiven();
    else if (value.empty() && readType == DATABASE)
        throw BitcoinExchange::BTCErrorWhileParsingDatabaseFile();
}

static void checkDateValueFormat(const std::string &key, const std::string &value, e_type readType = READFILE)
{
    if (!isValidDateFormat(key))
    {
        if (readType == DATABASE)
            throw BitcoinExchange::BTCErrorWhileParsingDatabaseFile();
        else if (readType == READFILE)
            throw BitcoinExchange::BTCInvalidDateFormat();
    }

    if (!isValidValueFormat(value))
    {
        if (readType == DATABASE)
            throw BitcoinExchange::BTCErrorWhileParsingDatabaseFile();
        else if (readType == READFILE)
            throw BitcoinExchange::BTCInvalidValueFormat();
    }
}

void checkValueRange(float &value)
{
    if (value < 0.0f)
        throw BitcoinExchange::BTCValueTooSmall();
    if (value > 1000.0f)
        throw BitcoinExchange::BTCValueTooBig();
}

/**
 * Store data from csv file into map (database)
 * 1. Separate the key (date string) and value (value string)
 * 2. Check if the date and the value follows the desired format
 * 3. Convert key to epoch time (time_t)
 * 4. Convert value into a float value
 * 5. Create a pair using the converted value
 * 6. Insert the pair into the database (map)
 */
static void storeDataToDatabase(const std::string &str, MapType &dataMap)
{
    try
    {
        std::string key;
        std::string value;

        // extract the key and value from the string
        extractKeyValue(str, key, value, ",", DATABASE);
        // check if the date and value format is expected
        checkDateValueFormat(key, value, DATABASE);

        // convert value to its corresponding type
        time_t keyAsEpochTime = strToEpochTime(key);
        float valueAsFloat = strtof(value.c_str(), NULL);
        
        // create a pair based on the key and value and insert the pair into the map
        std::pair<time_t, float> keyValuePair = std::make_pair(keyAsEpochTime, valueAsFloat);
        dataMap.insert(keyValuePair);
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what();
        std::cout << BRED << str << RESET << std::endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * Print out the updated exchange rate
 * 1. Seperate the given string into key and value
 * 2. Check their format, if there's an error, return so that it can skip to next record.
 * 3. Convert key and value into its coresponding type
 * 4. Check if the value exceed the range
 * 5. Get the value using lower_bound based on the key
 *       - lower than any of the key, return begin()
 *       - greater than any of the key, return end()
 *       - exact same key, return that record
 *    NOTE: the return record if not same key is actually record + 1, so to access the "true" lower bound,
 *          need to get the previous record.
 * 6. Print out the updated exchange rate, no need to modify the database
 */
static void updateExchangeRate(const std::string &str, MapType &dataMap)
{
    std::string key;
    std::string value;

    try
    {
        // extract the key and value from the string (including checking if key or value is empty, delimeter not found)
        extractKeyValue(str, key, value, " | ");
        // check if the date and value format is expected
        checkDateValueFormat(key, value);

        // convert value to its corresponding type
        time_t keyAsEpochTime = strToEpochTime(key);
        float valueAsFloat = strtof(value.c_str(), NULL);

        // check if the value is within range (0-1000)
        checkValueRange(valueAsFloat);

        // search for the record in the map
        MapType::iterator record = dataMap.lower_bound(keyAsEpochTime);
        // if the record is not the first record in the map AND the key is not the same as the key we are going to use,
        // set record to the record we found - 1 position.
        if (record != dataMap.begin() && record->first != keyAsEpochTime)
            record = std::prev(record);
        // print the output
        std::cout << epochTimeToStr(keyAsEpochTime) << " => " << value << " = " << record->second * valueAsFloat << std::endl;
    }
    catch (const BitcoinExchange::BTCInvalidDateFormat &ex)
    {
        std::cout << ex.what();
        std::cout << BRED << key << RESET << std::endl;
    }
    catch (const BitcoinExchange::BTCInvalidValueFormat &ex)
    {
        std::cout << ex.what();
        std::cout << BRED << value << RESET << std::endl;
    }
    catch (const BitcoinExchange::BTCValueTooBig &ex)
    {
        std::cout << ex.what();
        std::cout << BRED << value << RESET << std::endl;
    }
    catch (const BitcoinExchange::BTCValueTooSmall &ex)
    {
        std::cout << ex.what();
        std::cout << BRED << value << RESET << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what();
        std::cout << BRED << str << RESET << std::endl;
    }
    return;
}

/**
 * Make this function generic.
 * A generic function to run when reading the file, so that it can perform an action to each line.
 */
static void getLineFromFile(std::ifstream &file, MapType &dataMap, void (*func)(const std::string &str, MapType &datamap), e_type readType = READFILE)
{
    std::string line;

    // if read from database, skip the first line
    if (readType == DATABASE)
        std::getline(file, line);
    while (std::getline(file, line))
        func(line, dataMap);
    file.close();
}

/**
 * Bitcoin exchange
 * 1. Check if database and the given file can be accessed
 * 2. Read the databse file and store each record into the database (map)
 * 3.
 */
void BitcoinExchange::bitcoinExchange(const std::string &file)
{
    std::ifstream database;
    std::ifstream readFile;
    MapType dataMap;

    checkFile(database, readFile, file);
    getLineFromFile(database, dataMap, storeDataToDatabase, DATABASE);
    getLineFromFile(readFile, dataMap, updateExchangeRate);
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
    return "[ERROR]: Failed to parse database data => ";
}

const char *BitcoinExchange::BTCInvalidDateFormat::what() const throw()
{
    return "[ERROR]: Invalid date format => ";
}

const char *BitcoinExchange::BTCInvalidValueFormat::what() const throw()
{
    return "[ERROR]: Invalid value format => ";
}

const char *BitcoinExchange::BTCValueTooBig::what() const throw()
{
    return "[ERROR]: Value too big => ";
}

const char *BitcoinExchange::BTCValueTooSmall::what() const throw()
{
    return "[ERROR]: Value too small => ";
}

const char *BitcoinExchange::BTCEmptyLine::what() const throw()
{
    return "[ERROR]: Empty line! Skip!";
}

const char *BitcoinExchange::BTCFailedToParseLine::what() const throw()
{
    return "[ERROR]: Failed to parse line => ";
}

const char *BitcoinExchange::BTCNoDateGiven::what() const throw()
{
    return "[ERROR]: Date missing => ";
}

const char *BitcoinExchange::BTCNoValueGiven::what() const throw()
{
    return "[ERROR]: Value missing => ";
}