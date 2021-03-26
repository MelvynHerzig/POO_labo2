/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Cargo.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 17/03/2021

 But         : Implémente une classe "abstraite" Cargo héritant de Ship.
               Elle ajoute une notion de charge avec un poids.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_CARGO_H
#define LABO2_CARGO_H


#include <string>  // std::string
#include <ostream> // std::ostream
#include "../Ship.h"

/**
 * @brief Implémente les cargos abstraits
 * @author Forestier Quentin & Herzig Melvyn
 * @version 1.0.0
 */
class Cargo : public Ship
{
   typedef Ship super;

private:
   /**
    * Poids du chargement
    */
   double loadWeight;

public:
   /**
    * Constructeur
    * @param id Identifiant du cargo.
    * @param loadWeight Poids du chargement (tonnes).
    * @param nickname (facultatif) Nom du vaisseau.
    */
   Cargo (unsigned id, double loadWeight, const std::string &nickname = "");

   /**
   * @brief Destructeur.
   */
   virtual ~Cargo()
   {}

   /**
   * @brief Insère un cargo dans un flux.
   * @param os Flux recevant le cargo.
   * @return Retourne le flux avec le cargo inséré.
   */
   virtual std::ostream &toStream (std::ostream &os) const;

   /**
    * @brief Initialise le poids du chargement du cargo.
    * @param loadWeight Poids à définir (tonnes).
    * @throw invalid_argument si le poids du chargement est supérieur au poids max.
    */
   void setLoadWeight (double loadWeight);

   /**
    * @brief Accesseur poids total du cargo.
    * @return Retourne le poids total du cargo (tonnes)
    */
   virtual double getWeight () const;

   /**
    * @brief Accesseur poids de chargement maximal du cargo.
    * @return Retourne le poids maximal du chargement. (tonnes)
    */
   virtual double getMaxLoadWeight () const = 0;

   /**
    * @brief Accesseur du poids à vide du cargo.
    * @return Retourne le poids à vide du cargo. (tonnes)
    */
   virtual double getEmptyWeight () const = 0;

};


#endif //LABO2_CARGO_H
