/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:36:11 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/24 22:19:21 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

enum    e_file_perm {
    WRITE_ONLY,
    READ_ONLY
};

/**
 * @brief The core logic. Replace occurrences of oldStr with newStr.
 * 
 * @details
 * 1. Find the first occurrence of oldStr in the line
 * 2. When found, write the line from the beginning to the first occurrence of oldStr
 * 3. Write newStr
 * 4. Update the position to the end of the first occurrence of oldStr
 * 5. Repeat until no more occurrences of oldStr are found
 * 6. Write the rest of the line
*/
static void replace_and_write(std::fstream& dest, std::string line, std::string oldStr, std::string newStr) {

    size_t      pos = 0;
    size_t      index = 0;

    while ((pos = line.find(oldStr, pos)) != std::string::npos)
    {
        dest << line.substr(index, pos - index);
        dest << newStr;
        pos += oldStr.length();
        index = pos;
    }
    dest << line.substr(index, line.length() - index);
}

/**
 * @brief Open file with specified permissions
 * 
 * @details
 * Based on the given permission, opens the file for reading or writing.
 * std::ios::out - Open for output operations.
 * std::ios::in - Open for input operations.
 * After opening the file, checks if it was opened successfully.
 * 
 * @attention Only WRITE_ONLY and READ_ONLY are allowed
*/
static void open_file(std::fstream &file, std::string filename, e_file_perm perm) {
    
    if (perm != WRITE_ONLY && perm != READ_ONLY)
        return ;
    if (perm == WRITE_ONLY)
        file.open(filename.c_str(), std::ios::out);
    else if (perm == READ_ONLY)
        file.open(filename.c_str(), std::ios::in);
    if (file.is_open() == false)
    {
        std::cerr << "Error " << (perm == WRITE_ONLY ? "creating " : "reading ") << filename << "\n";
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Sed is for losers
 * 
 * @var r_file - The file to read from
 * @var w_file - The file to write to
 * @var w_file_name - The name of the file to write to
 * @var line - The line to read from the file
 * 
 * @details
 * 1. Parse the arguments
 * 2. Open the file for reading
 * 3. Open the file for writing and also decide the name of the file
 * 4. Read the file line by line. For each line, replace every occurence of oldStr with newStr
 * 5. Close the files once it's done
 * 
 * @attention 
 * The `<<` operator is overloaded for std::fstream to enable writing data into a file.
*/
int main(int ac, char **av) {

    std::fstream    r_file;
    std::fstream    w_file;
    std::string     w_file_name;
    std::string     line;

    if (ac != 4) {
        std::cout << "./sed_is_for_losers <filename> <oldStr> <newStr>\n";
        exit(EXIT_FAILURE);
    } else if (std::string(av[2]).empty() == true) {
        std::cout << "<oldStr> is empty!\n";
        exit(EXIT_FAILURE);   
    }

    open_file(r_file, av[1], READ_ONLY);
    w_file_name = std::string(av[1]) + ".replace";
    open_file(w_file, w_file_name, WRITE_ONLY);

    while (std::getline(r_file, line)) {
        replace_and_write(w_file, line, av[2], av[3]);
        w_file << "\n";
    }

    r_file.close();
    w_file.close();
}
