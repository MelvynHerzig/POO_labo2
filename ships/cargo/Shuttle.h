/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Shuttle.h
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 17/03/2021

 But         : Implémente une vaisseau "Navette impériale".
               Définit son poids, le nom du modèle, et sa charge ainsi que sa
               vitesse.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_SHUTTLE_H
#define LABO2_SHUTTLE_H

#include "Cargo.h"

class Shuttle : public Cargo
{
    typedef Cargo super;

private:
    static unsigned count;

public:
    Shuttle(double loadWeight = 0, const std::string& nickname = "");

    virtual double getWeight() const;

    virtual unsigned getSpeed() const;

    virtual std::string getModel() const;

    virtual double getMaxCargoWeight() const;
};


#endif //LABO2_SHUTTLE_H
