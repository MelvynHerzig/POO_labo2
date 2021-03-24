/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Ship.h
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 17/03/2021

 But         : Implémente une classe "abstraite" qui modélise un vaisseau.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_SHIP_H
#define LABO2_SHIP_H

#include <cstdlib>
#include <string>

class Ship;

std::ostream& operator << (std::ostream& os, const Ship& ship);

class Ship
{
private:

    unsigned id;
    std::string nickname;

public:
    Ship(unsigned id, const std::string& nickname);

    double consumption(double distance) const;

    virtual double getWeight() const = 0;

    virtual unsigned getSpeed() const = 0;

    virtual std::string getModel() const = 0;

    unsigned getId() const;

    virtual std::ostream& toStream(std::ostream& os) const;

};


#endif //LABO2_SHIP_H
