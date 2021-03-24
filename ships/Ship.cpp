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
#include <iomanip>
#include <ostream>

using namespace std;

std::ostream &operator<<(std::ostream &os, const Ship &ship)
{
   return ship.toStream(os);
}

Ship::Ship(unsigned int id, const std::string& nickname) : id(id), nickname(nickname)
{}

void Ship::setNickname (const std::string &nickname)
{
   this->nickname = nickname;
}

double Ship::consumption(double distance) const
{
    return (std::pow(getWeight(), 1.0/3.0) / 2) * std::log10(getWeight()*getSpeed()) * std::log10(distance+1);
}

std::ostream& Ship::toStream(std::ostream& os) const
{
    return os << nickname << " [" << getModel() << " #" << getId() << "]" << std::endl
              << "\t weight :" << fixed << setprecision(2) << getWeight() << " tons" << std::endl
              << "\t max speed : " << getSpeed() << " MGLT";
}

unsigned Ship::getId() const
{
    return id;
}



