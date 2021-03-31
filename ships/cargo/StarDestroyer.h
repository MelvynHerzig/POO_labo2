/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : StarDestroyer.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 17/03/2021

 But         : Implémente une vaisseau "Star Dreadnought".
               Définit son poids, le nom du modèle, et sa charge ainsi que sa
               vitesse.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_STARDESTROYER_H
#define LABO2_STARDESTROYER_H

#include <string> // std::string
#include "Cargo.h"

/**
 * @brief Implémente les Star Dreadnought
 * @author Forestier Quentin & Herzig Melvyn
 * @version 1.0.0
 */
class StarDestroyer : public Cargo
{
   typedef Cargo super;

private:
   /**
   * @brief Compteur des Star Dreadnought créés.
   */
   static unsigned count;

   /**
    * @brief Poids des Star Dreadnought (Tonnes)
    */
   static const double WEIGHT;
   /**
    * @brief Poids maximal des Star Dreadnought (Tonnes)
    */
   static const double MAX_LOAD_WEIGHT;
   /**
    * @brief Vitesse des Star Dreadnought (MGLT)
    */
   static const unsigned SPEED;
   /**
    * @brief Modèle des Star Dreadnought (tonnes)
    */
   static const std::string MODEL;

public:
   /**
    * @brief Constructeur par défaut, définit un nom vide.
    * @param nickname (faculatif) nom.
    */
   StarDestroyer (double loadWeight = 0, const std::string &nickname = "");

   /**
   * @brief Accesseurs de la vitesse.
   * @return Retourne la vitesse des Star Dreadnought
   */
   unsigned getSpeed () const override;

   /**
    * @brief Accesseurs du modèle.
    * @return Retourne le modèle des Star Dreadnought
    */
   std::string getModel () const override;

   /**
    * @brief Accesseurs du poids maximal.
    * @return Retourne le poids maximal des Star Dreadnought
    */
   double getMaxLoadWeight () const override;

   /**
    * @brief Accesseurs du poids à vide.
    * @return Retourne le poids des Star Dreadnought
    */
   double getEmptyWeight () const override;
};


#endif //LABO2_STARDESTROYER_H
