/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Cargo.h
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 17/03/2021

 But         : Implémente une classe "abstraite" Cargo héritant de Ship.
               Elle ajoute une notion charge avec un poids.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_CARGO_H
#define LABO2_CARGO_H


#include <string>
#include "../Ship.h"

class Cargo : public Ship
{
     typedef Ship super;

private:
    double loadWeight;

public:
    Cargo(unsigned count, double loadWeight, const std::string& nickname = "");

    virtual std::ostream& toStream(std::ostream& os) const;

    virtual double getMaxCargoWeight() const = 0;

    // Throws invalid_argument
    void setLoadWeight(double loadWeight);

    virtual double getWeight() const;

    virtual double getEmptyWeight() const = 0;

};


#endif //LABO2_CARGO_H
