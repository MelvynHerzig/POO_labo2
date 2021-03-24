/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : TIEIN.h
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 17/03/2021

 But         : Implémente une vaisseau "Intercepteur TIE".
               Définit son poids, le nom du modèle ainsi que sa vitesse.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_TIEIN_H
#define LABO2_TIEIN_H


#include "../Ship.h"

class TIEIN : public Ship
{
    typedef Ship super;

private:
    static unsigned count;

public:
    TIEIN(const std::string& nickname = "");

    virtual double getWeight() const;

    virtual unsigned getSpeed() const;

    virtual std::string getModel() const;
};


#endif //LABO2_TIEIN_H
