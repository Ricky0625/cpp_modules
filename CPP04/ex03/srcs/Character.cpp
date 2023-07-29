/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:20:01 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/29 17:59:33 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iomanip>

typedef enum e_role {
    DEFAULT,
    WIZARD,
}   t_role;

static void showNameTag(std::string name, t_role role = WIZARD)
{
    std::cout << BYELLOW << "🧙 [" << name << (role == DEFAULT ? "(default)" : "") << "]" << RESET << ": ";
}

// default constructor
Character::Character() : _name("unknown")
{
    _inventorySize = 0;
    // The inventory is empty at construction
    for (int i = 0; i < MAX_INVENTORY; i++)
        _inventory[i] = NULL;
    
    _dustbinSize = 0;
    // The table is empty at construction
    for (int i = 0; i < MAX_BIN_CAPACITY; i++)
        _dustbin[i] = NULL;
    showNameTag(_name, DEFAULT);
    // std::cout << BYELLOW << "🧙 [" << _name << "(default)]" << RESET << ": A magical hello to you" << std::endl;
}

/**
 * @brief Construct a new Character:: Character object
 * 
 * @attention
 * Inventory: Can be used to store up to 4 materia, can be used
 * Table: Can be used to store up to 10 materia, cannot be picked up
*/
Character::Character(std::string name) : _name(name)
{
    _inventorySize = 0;
    // The inventory is empty at construction
    for (int i = 0; i < MAX_INVENTORY; i++)
        _inventory[i] = NULL;
    
    _dustbinSize = 0;
    // The table is empty at construction
    for (int i = 0; i < MAX_BIN_CAPACITY; i++)
        _dustbin[i] = NULL;
    showNameTag(_name);
    // std::cout << "A magical hello to you" << std::endl;
}

// copy constructor (need to perform deep copy)
Character::Character(const Character &other)
{
    _name = other._name;
    _inventorySize = other._inventorySize;
    _dustbinSize = other._dustbinSize;
    // The inventory is empty at construction
    for (int i = 0; i < MAX_INVENTORY; i++)
        _inventory[i] = NULL;

    // The table is empty at construction
    for (int i = 0; i < MAX_BIN_CAPACITY; i++)
        _dustbin[i] = NULL;
    
    // copy inventory
    for (int i = 0; i < _inventorySize; i++)
        _inventory[i] = other._inventory[i]->clone();
    
    // copy dustbin
    for (int i = 0; i < _dustbinSize; i++)
        _dustbin[i] = other._dustbin[i]->clone();
    
    showNameTag(_name);
    // std::cout << "Copy constructor called!" << std::endl;
}

// assignment operator (overload, need to perform deep copy)
Character    &Character::operator=(const Character &other)
{
    // check for self-assignment
    if (this == &other)
        return *this;
        
    // delete all materia in inventory
    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        delete _inventory[i];
        _inventory[i] = NULL;
    }
    
    // delete all materia in dustbin
    for (int i = 0; i < MAX_BIN_CAPACITY; i++)
    {
        delete _dustbin[i];
        _dustbin[i] = NULL;
    }

    
    // copy inventory
    for (int i = 0; i < _inventorySize; i++)
        _inventory[i] = other._inventory[i]->clone();
    
    // copy dustbin
    for (int i = 0; i < _dustbinSize; i++)
        _dustbin[i] = other._dustbin[i]->clone();
    
    _name = other._name;
    _inventorySize = other._inventorySize;
    _dustbinSize = other._dustbinSize;
    showNameTag(_name);
    // std::cout << "Assignment operator called!" << std::endl;
    return *this;
}

// destructor
Character::~Character()
{
    // delete all materia in inventory
    showNameTag(_name);
    std::cout << "Cleaning up my inventory..." << std::endl;
    for (int i = 0; i < MAX_INVENTORY; i++)
        delete _inventory[i];
    // delete all materia in dustbin
    showNameTag(_name);
    std::cout << "Cleaning up my dustbin..." << std::endl;
    for (int i = 0; i < MAX_BIN_CAPACITY; i++)
        delete _dustbin[i];
    std::cout << BYELLOW << "🧙 [" << _name << "]" << RESET << ": Stay magical, goodbye!" << std::endl;
}

// override
std::string const &Character::getName() const {
    return this->_name;
}

void Character::throwAway(AMateria *m)
{
    if (_dustbinSize == MAX_BIN_CAPACITY)
    {
        showNameTag(_name);
        std::cout << "Oh no. The dustbin is full. Well, I guess I'll throw it to the fire." << std::endl;
        delete m; // even though the subject says `unequip` must NOT delete the materia, but if the dustbin is full, we have no choice but to delete it
        return ;
    }
    _dustbin[_dustbinSize++] = m;
}

void Character::equip(AMateria *m)
{
    // if there is no materia to equip
    if (m == NULL)
    {
        showNameTag(_name);
        std::cout << "I have nothing to equip." << std::endl;
        return ;
    }

    // search for empty slot
    int slot_idx = 0;
    while (slot_idx < MAX_INVENTORY && _inventory[slot_idx] != NULL)
        slot_idx++;
    
    // if there is no empty slot
    if (slot_idx == MAX_INVENTORY)
    {
        showNameTag(_name);
        std::cout << "I have no empty slots. Throw " << m->getType() << " to the dustbin." << std::endl;
        throwAway(m);
        return ;
    }
    
    // equip materia
    _inventory[slot_idx] = m;
    _inventorySize++;
    showNameTag(_name);
    std::cout << "Equiped " << m->getType() << " at slot " << slot_idx << "." << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= MAX_INVENTORY)
    {
        showNameTag(_name);
        std::cout << "Invalid slot index." << std::endl;
        return ;
    }
    
    if (_inventory[idx] == NULL)
    {
        showNameTag(_name);
        std::cout << "Slot " << idx << " is empty." << std::endl;
        return ;
    }
    
    // throw materia to the dustbin
    throwAway(_inventory[idx]);
    // unequip materia
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    showNameTag(_name);

    // check if idx is valid
    if (idx < 0 || idx >= MAX_INVENTORY)
    {
        std::cout << "Invalid slot index." << std::endl;
        return ;
    }

    AMateria *m = _inventory[idx];
    
    // check if materia exists in the slot
    if (m == NULL)
    {
        std::cout << "Slot " << idx << " is empty." << std::endl;
        return ;
    }

    // use materia
    m->use(target);
}

void Character::showMateriaTypeAsEmoji(int idx, t_storage_type type) const
{
    if ((type == INVENTORY && (idx < 0 || idx >= MAX_INVENTORY)) || (type == DUSTBIN && (idx < 0 || idx >= MAX_BIN_CAPACITY)))
    {
        std::cout << " ";
        return ;
    }
    
    AMateria *m = (type == INVENTORY ? _inventory[idx] : _dustbin[idx]);
    
    if (m == NULL)
        std::cout << " ";
    else if (m->getType() == "ice")
        std::cout << BGBLUE << "🧊[ICE]" << RESET;
    else if (m->getType() == "cure")
        std::cout << BGGREEN << "💊[CURE]" << RESET;
    else 
        std::cout << " ";
}

void    Character::showSlots(t_storage_type type) const
{
    if (type != INVENTORY && type != DUSTBIN) return;
    showNameTag(_name);
    if (type == INVENTORY)
        std::cout << _name << "'s inventory" << std::endl;
    else
        std::cout << _name << "'s dustbin" << std::endl;
    std::cout << BWHITE << " SLOT:MATERIA" << RESET << std::endl;
    for (int i = 0; i < (type == INVENTORY ? MAX_INVENTORY : MAX_BIN_CAPACITY); i++)
    {
        std::cout << BWHITE << std::setw(5) << i << ":" << RESET;
        showMateriaTypeAsEmoji(i, type);
        std::cout << std::endl;
    }
}
