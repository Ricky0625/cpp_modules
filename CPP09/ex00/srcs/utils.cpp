#include "BitcoinExchange.hpp"

// date utils
/**
 * @brief Check if the given year is a leap year
 * In the Gregorian calendar, a leap year occurs every 4 years,
 * except for years that are divisible by 100 but not divisible by 400.
*/
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 * @brief Check if the given year, month and day forms a valid date
*/
bool isValidDate(int year, int month, int day)
{
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return day <= 29;
    return day <= daysInMonth[month];
}

// time utils
/**
 * @brief extract the date from a string into year, month and day
*/
static bool extractDate(const std::string &date, int &year, int &month, int &day)
{
    std::istringstream dateStream(date);
    char dash1, dash2;

    dateStream >> year >> dash1 >> month >> dash2 >> day;
    if (dateStream.fail() || dash1 != '-' || dash2 != '-')
        return false;
    return true;
}

/**
 * @brief Convert date string into epoch time
*/
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

/**
 * @brief Convert epoch time (time_t) to string
*/
std::string epochTimeToStr(time_t epochTime)
{
    std::tm *timeInfo = std::localtime(&epochTime);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeInfo);

    return buffer;
}

// format utils
/**
 * @brief Check if the given date string is a valid date format
*/
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

/**
 * @brief Check if the value is in INT format
*/
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

/**
 * @brief Check if the value is in FLOAT format
*/
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

// general utils
/**
 * @brief Check if a character only appear once in the string
*/
bool onlyHasOneOccurrence(const std::string &str, char target)
{
    return (str.find_first_of(target) == str.find_last_of(target));
}

