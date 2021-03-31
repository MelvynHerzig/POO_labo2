/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : SquadronOperation.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 24/03/2021

 But         : Classe abstraite définissant la classe à implémenter
               pour gérer l'ajout/suppression de vaisseaux dans l'escadron.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_SQUADRONOPERATION_H
#define LABO2_SQUADRONOPERATION_H

#include "../Squadron.h" // Squadron

// Pré-déclaration pour utiliser les escadrilles.
class Squadron;

/**
 * @brief Classe interface définisant les opérations sur les escadrilles
 *        servira pour l'ajout et le retrait de vaisseaux.
 * @authors Forestier Quentin et Herzig Melvyn
 * @version 1.0.0
 */
class SquadronOperation
{
   friend Squadron;

public:

   /**
    * @brief destructeur.
    */
   virtual ~SquadronOperation() = default;

private:
   /**
    * @brief Applique une transformation sur l'escadron.
    * @param squadron Escadron concernée.
    * @param ship Vaisseau impliqué.
    * @throws invalid_argument (par SquadAdd et SquadRemove)
    */
   virtual void operator()(Squadron& squadron, const Ship* ship) const = 0;
};

#endif //LABO2_SQUADRONOPERATION_H
