/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : SquadronRemove.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 24/03/2021

 But         : Implémente la méthode qui permet d'enlever un vaisseau de
               l'escadron.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_SQUADRONREMOVE_H
#define LABO2_SQUADRONREMOVE_H

#include "SquadronOperation.h" // SquadronOperation

/**
 * @brief Classe définissant la procédure de retrait d'un vaisseau.
 * @authors Forestier Quentin et Herzig Melvyn
 * @version 1.0.0
 */
class SquadronRemove : public SquadronOperation
{
private:
   /**
   * @brief Retire un vaisseau de l'escadron.
   * @param squadron Escadron concernée.
   * @param ship Vaisseau impliqué.
   * @throws invalid_argument si ship est nullptr.
   * @details Le vaisseau retiré est remplacé par le dernier dans le tableau.
   */
   void operator()(Squadron& squadron, const Ship* ship) const override;
};

#endif //LABO2_SQUADRONREMOVE_H
