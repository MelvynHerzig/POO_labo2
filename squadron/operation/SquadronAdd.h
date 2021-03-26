/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : SquadronAdd.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 24/03/2021

 But         : Implémente la méthode qui permet d'ajouter un vaisseau de
               l'escadrille.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_SQUADRONADD_H
#define LABO2_SQUADRONADD_H

#include "SquadronOperation.h"

/**
 * @brief Classe définissant la procédure d'ajout d'un vaisseau.
 * @authors Forestier Quentin et Herzig Melvyn
 * @version 1.0.0
 */
class SquadronAdd : public SquadronOperation
{
private:
   /**
    * @brief Classe définissant la procédure d'ajout' d'un vaisseau.
    * @authors Forestier Quentin et Herzig Melvyn
    * @version 1.0.0
    */
   virtual void operator()(Squadron& squadron, const Ship* ship) const;
};

#endif //LABO2_SQUADRONADD_H
