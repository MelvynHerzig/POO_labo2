/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Ship.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 17/03/2021

 But         : Implémente une classe "abstraite" qui modélise un vaisseau.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_SHIP_H
#define LABO2_SHIP_H

#include <ostream> // std::ostream
#include <string>  // std::string

//pré-déclaration
class Ship;

/**
 * @brief Ajoute un vaisseau dans un flux.
 * @param os Flux dans lequel ajouter le vaisseau.
 * @param ship Vaisseau concerné.
 * @return Retourne le flux avec le vaisseau^.
 */
std::ostream &operator<< (std::ostream &os, const Ship &ship);

/**
 * @brief Classe qui modélise un vaisseau.
 * @author Forestier Quentin & Herzig Melvyn
 * @version 1.0.0
 */
class Ship
{
private:

   /**
    * @brief Identifiant du vaisseau
    */
   unsigned id;

   /**
    * Nom du vaisseau
    */
   std::string nickname;

public:

   // Comme les vaisseaux ont des id auto incrémentés et qu'aucune
   // précision n'est fournie sur la copie des vaisseaux, nous avons retiré
   // la possibilité de les copier
   Ship& operator=(const Ship&) = delete;
   Ship(const Ship& ship) = delete;

   /**
    * @brief Constructeur.
    * @param id Id à assigner au vaisseau
    * @param nickname Nom du vaisseau.
    */
   Ship (unsigned id, const std::string &nickname);

   /**
    * @brief destructeur.
    */
   virtual ~Ship()
   {}

   /**
    * @brief Mutateur du nom du vaisseau.
    * @param nickname Nouveau nom à appliquer.
    */
   void setNickname (const std::string &nickname);

   /**
   * @brief Accesseur identifiant du vaisseau.
   * @return Retourne l'identifiant du vaisseau.
   */
   unsigned getId () const;

   /**
    * @brief Insère un vaisseau dans un flux.
    * @param os Flux recevant le vaisseau
    * @return Retourne le flux avec le vaisseau inséré.
    */
   virtual std::ostream &toStream (std::ostream &os) const;

   /**
    * @brief Calcule la consommation du vaisseau.
    * @param distance Distance à parcourir (millions de kilomètres)
    * @return Retourne la consommation du vaisseau (tonnes)
    */
   double consumption (double distance) const;

   /**
    * @brief Accesseur du poids du vaisseau.
    * @return Retourne le poids du vaisseau.
    */
   virtual double getWeight () const = 0;

   /**
    * @brief Accesseur vitesse du vaisseau.
    * @return Retourne la vitesse du vaisseau.
    */
   virtual unsigned getSpeed () const = 0;

   /**
    * @brief Accesseur modèle du vaisseau.
    * @return Retourne le modèle du vaisseau.
    */
   virtual std::string getModel () const = 0;
};

#endif //LABO2_SHIP_H
