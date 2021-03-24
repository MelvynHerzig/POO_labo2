/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Ship.cpp
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 17/03/2021
 -----------------------------------------------------------------------------------
 */

#include "Ship.h"

#include <cmath>
#include <iostream>

Ship::Ship(unsigned int id, const std::string& nickname) : id(id), nickname(nickname)
{}

double Ship::consumption(double distance) const
{
    return (std::pow(getWeight(), 1.0/3.0) / 2) * std::log10(getWeight()*getSpeed()) * std::log10(distance+1);
}

std::ostream& Ship::toStream(std::ostream& os) const
{
    return os << nickname << " [" << getModel() << "]" << std::endl
              << "\t weight :" << getWeight() << " tons" << std::endl
              << "\t max speed : " << getSpeed() << " MGLT" << std::endl;
}

unsigned Ship::getId() const
{
    return id;
}


