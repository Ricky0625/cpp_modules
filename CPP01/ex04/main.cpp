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

enum    e_file_perm {
    WRITE_ONLY,
    READ_ONLY
};

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

static void open_file(std::fstream &file, std::string filename, e_file_perm perm) {
    
    if (perm != WRITE_ONLY && perm != READ_ONLY)
        return ;
    if (perm == WRITE_ONLY)
        file.open(filename, std::ios::out);
    else if (perm == READ_ONLY)
        file.open(filename, std::ios::in);
    if (file.is_open() == false)
    {
        std::cerr << "Error " << (perm == WRITE_ONLY ? "creating " : "reading ") << filename << "\n";
        exit(EXIT_FAILURE);
    }
}

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
