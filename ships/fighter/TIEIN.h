/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : TIEIN.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 17/03/2021

 But         : Implémente une vaisseau "Intercepteur TIE".
               Définit son poids, le nom du modèle ainsi que sa vitesse.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_TIEIN_H
#define LABO2_TIEIN_H

#include <string> // std::string
#include "../Ship.h"

/**
 * @brief Implémente les intercepteurs TIE
 * @author Forestier Quentin & Herzig Melvyn
 * @version 1.0.0
 */
class TIEIN : public Ship
{
   typedef Ship super;

private:
   /**
    * @brief Compteur des vaisseaux intercepteurs TIE créés.
    */
   static unsigned count;

   /**
    * @brief Poids des intercepteurs TIE (Tonnes)
    */
   static const double WEIGHT;
   /**
    * @brief Vitesse des intercepteurs TIE (MGLT)
    */
   static const unsigned SPEED;
   /**
    * @brief Modèle des intercepteurs TIE
    */
   static const std::string MODEL;

public:
   /**
    * @brief Constructeur par défaut, définit un nom vide.
    * @param nickname (faculatif) nom.
    */
   TIEIN (const std::string &nickname = "");

   /**
   * @brief Accesseurs du poids.
   * @return Retourne le poids des vaisseaux TIE
   */
   double getWeight () const override;

   /**
    * @brief Accesseurs de la vitesse.
    * @return Retourne la vitesse des vaisseaux TIE
    */
   unsigned getSpeed () const override;

   /**
    * @brief Accesseurs de la vitesse.
    * @return Retourne le modèle des vaisseaux TIE
    */
   std::string getModel () const override;
};


#endif //LABO2_TIEIN_H
