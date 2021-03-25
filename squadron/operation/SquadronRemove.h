/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : SquadronRemove.h
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 24/03/2021

 But         : Implémente la méthode qui permet d'enlever un vaisseau de
               l'escadrille.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_SQUADRONREMOVE_H
#define LABO2_SQUADRONREMOVE_H

#include "SquadronOperation.h"

class SquadronRemove : public SquadronOperation
{
public:
   virtual void operator()(Squadron& squadron, const Ship* ship) const;
};


#endif //LABO2_SQUADRONREMOVE_H
