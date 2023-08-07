/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:28:32 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/07 21:46:24 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void    setValue(Data *data)
{
    data->_id = 25062000;
    data->_name = "The meaning of life: 42";
    data->_price = 42.0;
}

void    printData(Data *data)
{
    // size_t  data_max_len = data->_name.length();
    size_t  identifier_max_len = std::string("price").length();

    std::cout << std::left << std::setw(identifier_max_len) << "id" << " | " << data->_id << "\n"
              << std::left << std::setw(identifier_max_len) << "name" << " | " << data->_name << "\n"
              << std::left << std::setw(identifier_max_len) << "price" << " | " << data->_price << std::endl;
}

int main()
{
    Data *data = new Data;

    setValue(data);
    std::cout << "Before: " << BGREEN << data << RESET << std::endl;
    printData(data);
    std::cout << std::endl;
    
    uintptr_t serialized = Serializer::serialize(data);
    std::cout<< "  Serialized: " << BCYAN << serialized << RESET << std::endl;
    Data *deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized: " << BCYAN << deserialized << RESET << std::endl;
    std::cout << std::endl;

    std::cout << "After: " << BGREEN << data << RESET << std::endl;
    printData(data);

    delete data;
}