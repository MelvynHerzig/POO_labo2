/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : SquadronAdd.h
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 24/03/2021

 But         : Implémente la méthode qui permet d'ajouter un vaisseau de
               l'escadrille.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_SQUADRONADD_H
#define LABO2_SQUADRONADD_H

#include "SquadronOperation.h"

class SquadronAdd : public SquadronOperation
{
public:
   void squadOp(Squadron& squadron, const Ship* ship) const;
};


#endif //LABO2_SQUADRONADD_H
