/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Shuttle.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 17/03/2021

 But         : Implémente une vaisseau "Navette impériale".
               Définit son poids, le nom du modèle, et sa charge ainsi que sa
               vitesse.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_SHUTTLE_H
#define LABO2_SHUTTLE_H

#include <string> // std::string
#include "Cargo.h"

/**
 * @brief Implémente les Navettes impériales
 * @author Forestier Quentin & Herzig Melvyn
 * @version 1.0.0
 */
class Shuttle : public Cargo
{
   typedef Cargo super;

private:
   /**
    * @brief Compteur des Navettes impériales créés.
    */
   static unsigned count;

   /**
    * @brief Poids des Navettes impériales (Tonnes)
    */
   static const double WEIGHT;
   /**
    * @brief Poids maximal des Navettes impériales (Tonnes)
    */
   static const double MAX_LOAD_WEIGHT;
   /**
    * @brief Vitesse des Navettes impériales (MGLT)
    */
   static const unsigned SPEED;
   /**
    * @brief Modèle des Navettes impériales (tonnes)
    */
   static const std::string MODEL;

public:
   /**
    * @brief Constructeur par défaut, définit un nom vide.
    * @param nickname (faculatif) nom.
    */
   Shuttle (double loadWeight = 0, const std::string &nickname = "");

   /**
   * @brief Destructeur.
   */
   virtual ~Shuttle()
   {}

   /**
    * @brief Accesseurs de la vitesse.
    * @return Retourne la vitesse des Navettes impériales
    */
   virtual unsigned getSpeed () const;

   /**
    * @brief Accesseurs du modèle.
    * @return Retourne le modèle des Navettes impériales
    */
   virtual std::string getModel () const;

   /**
    * @brief Accesseurs du poids maximal.
    * @return Retourne le poids maximal des Navettes impériales
    */
   virtual double getMaxLoadWeight () const;

   /**
    * @brief Accesseurs du poids à vide.
    * @return Retourne le poids des Navettes impériales
    */
   virtual double getEmptyWeight () const;
};


#endif //LABO2_SHUTTLE_H
