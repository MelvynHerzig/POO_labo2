/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : SquadronOperation.h
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 24/03/2021

 But         : Classe abstraite définissant la classe à implémenter
               pour gérer l'ajout/suppression de vaisseaux dans l'escadrille.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_SQUADRONOPERATION_H
#define LABO2_SQUADRONOPERATION_H

#include "../Squadron.h" // Squadron

class Squadron;

class SquadronOperation
{
public:
   // Throws invalid_argument
   virtual void operator()(Squadron& squadron, const Ship* ship) const = 0;
};


#endif //LABO2_SQUADRONOPERATION_H
