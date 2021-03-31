/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Squadron.h
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 17/03/2021

 But         : Implémente une esquadrille. Il est possible d'ajouter ou d'enlever
               des vaisseaux qui la compose. Il est possible d'ajouter ou
               supprimer son chef (facultatif). Elle peut être renommée.
               Il est possible d'afficher la consommation totale de l'escadron.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_SQUADRON_H
#define LABO2_SQUADRON_H


#include <string>           // std::string
#include <ostream>          // std::ostream
#include "../ships/Ship.h"  // Ship

// Pré-déclarations
class SquadronOperation;
class SquadronAdd;
class SquadronRemove;

/**
 * @brief Classe définissant un escadron de Ship
 *        Il est possible d'a ajouter des vaisseaux et de les retirer
 *        Lorsqu'un vaisseau est retiré, le dernier vaisseau ajouté
 *        prend sa position. L'ordre n'est donc pas garanti.
 *        Les vaisseaux sont considérés comme égaux s'ils ont la même adresse
 *        mémoire.
 * @authors Forestier Quentin et Herzig Melvyn
 * @version 1.0.0
 */
class Squadron
{
   // Classe implémentant l'ajout et la suppression d'un vaisseau dans l'escadron.
   friend SquadronAdd;
   friend SquadronRemove;

   /**
    * @brief Opérateur +.
    * @param squadron Escadron à ajouter le vaisseau.
    * @param ship Vaisseau à ajouter.
    * @return Retourne une copie de l'escadron avec le vaisseau
    * @throw invalide_argument Si le vaisseau est nullptr.
    * @details si le vaisseau est déjà dans l'escadron, retourne une copie de
    *          l'escadron.
    */
   friend Squadron operator+ (const Squadron &squadron, const Ship* ship);
   /**
    * @brief Opérateur +.
    * @param ship Vaisseau à ajouter.
    * @param squadron Escadron à ajouter le vaisseau.
    * @return Retourne une copie de l'escadron avec le vaisseau
    * @throw invalide_argument Si le vaisseau est nullptr.
    * @details si le vaisseau est déjà dans l'escadron, retourne une copie de
    *          l'escadron.
    */
   friend Squadron operator+ (const Ship* ship, const Squadron &squadron);

   /**
    * @brief Opérateur -.
    * @param squadron Escadron à retirer le vaisseau.
    * @param ship Vaisseau à retirer.
    * @return Retourne une copie de l'escadron sans le vaisseau
    * @throw invalide_argument Si le vaisseau est nullptr.
    * @details si le vaisseau n'est pas dans l'escadron, retourne une copie de
    *          l'escadron.
    */
   friend Squadron operator- (const Squadron &squadron, const Ship* ship);
   /**
    * @brief Opérateur -.
    * @param ship Vaisseau à retirer.
    * @param squadron Escadron à retirer le vaisseau.
    * @return Retourne une copie de l'escadron sans le vaisseau
    * @throw invalide_argument Si le vaisseau est nullptr.
    * @details si le vaisseau n'est pas dans l'escadron, retourne une copie de
    *          l'escadron.
    */
   friend Squadron operator- (const Ship* ship, const Squadron &squadron);

   /**
    * @brief Opérateur d'écriture dans un flux.
    * @param os Flux à écrire.
    * @param squadron Squadron à insérer dans le flux.
    * @return Retourne le flux avec l'escadron insérée.
    */
   friend std::ostream& operator<<(std::ostream& os, const Squadron& squadron);

private:
   /**
    * @brief Classe gérant l'ajout d'un vaisseau dans l'escadron.
    */
   static const SquadronOperation& APPLY_ADD;
   /**
   * @ brief Classe gérant le retrait d'un vaisseau dans l'escadron.
   */
   static const SquadronOperation& APPLY_REMOVE;

   /**
   * @brief Taille de base d'un escadron.
   */
   static const size_t DEFAULT_SQUAD_CAPACITY;


   /**
    * @brief Liste des vaisseaux dans l'escadron.
    */
   const Ship** squad;

   /**
    * @brief Capacité de l'escadron.
    */
   size_t squadCapacity;

   /**
    * @brief Nombre de vaisseaux dans l'escadron.
    */
   size_t squadSize;

   /**
    * @brief Chef de l'escadron.
    */
   const Ship*  leader;

   /**
    * @brief Nom de l'escadron
    */
   std::string  name;

public:
   // ----------------- Constructeurs / Destructeur -------------------
   /**
    * @brief Constructeur par défaut. Permet de spécifier un nom à l'escadron
    * @param name (Facultatif) Nom de l'escadron.
    * @details N'affecte aucun leader et la capacité par défaut.
    */
   Squadron(const std::string& name = "");
   /**
    * @brief Constructeur de copie.
    * @param otherSquadron Escadron à copier.
    */
   Squadron(const Squadron& otherSquadron);

   /**
    * @brief Destructeur de l'escadron. Libère l'espace mémoire
    *        pour sur les pointeurs des vaisseaux.
    */
   ~Squadron();

   // ----------------- Opérateurs -------------------
   /**
    * @brief Opérateur +=. Ajoute le vaisseau à l'escadron
    * @param ship Vaisseau à ajouter.
    * @return Retourne une référence sur l'escadron avec le vaisseau.
    * @throw invalide_argument Si le vaisseau est nullptr.
    * @details Si le vaisseau est déjà dans l'escadron, il n'y est pas re-ajouté.
    */
   Squadron& operator+=(const Ship* ship);
   /**
    * @brief Opérateur -=. Retire le vaisseau de l'escadron
    * @param ship Vaisseau à retirer.
    * @return Retourne une référence sur l'escadron sans le vaisseau.
    * @throw invalide_argument Si le vaisseau est nullptr.
    * @details Si le vaisseau n'est pas dans l'escadron, aucun effet.
    */
   Squadron& operator-=(const Ship* ship);

   /**
    * @brief Opérateur d'affectation.
    * @param otherSquadron Escadron à affecter.
    * @return Retourne une référence sur l'objet courant avec les
    *          caratéristique de otherSquadron.
    */
   Squadron& operator =(const Squadron& otherSquadron);

   /**
    * @brief Ajoute le vaisseau ship à une copie de l'escadron.
    * @param ship Vaisseau à ajouter.
    * @return Retourne une copie de l'escadron avec le vaisseau
    * @throw invalide_argument Si le vaisseau est nullptr.
    * @details Si le vaisseau est déjà dans l'escadron, retourne une copie de
    *          l'escadron.
    */
   Squadron add(const Ship* ship) const;

   /**
    * @brief Retire le vaisseau ship à une copie de l'escadron.
    * @param ship Vaisseau à retirer.
    * @return Retourne une copie de l'escadron sans le vaisseau.
    * @throw invalide_argument Si le vaisseau est nullptr.
    * @details Si le vaisseau n'est pas dans l'escadron, retourne une copie de
    *          l'escadron.
    */
   Squadron remove(const Ship* ship) const;

   /**
    * @brief Ajoute le vaisseau à l'escadron
    * @param ship Vaisseau à ajouter.
    * @return Retourne une référence sur l'escadron avec le vaisseau.
    * @throw invalide_argument Si le vaisseau est nullptr.
    * @details Si le vaisseau est déjà dans l'escadron, il n'y est pas re-ajouté.
    */
   Squadron& addSelf(const Ship* ship);
   /**
    * @brief Retire le vaisseau de l'escadron
    * @param ship Vaisseau à retirer.
    * @return Retourne une référence sur l'escadron sans le vaisseau.
    * @throw invalide_argument Si le vaisseau est nullptr.
    * @details Si le vaisseau n'est pas dans l'escadron, aucun effet.
    */
   Squadron& removeSelf(const Ship* ship);

   // ----------------- Mutateur -------------------
   /**
    * @brief Change le nom de l'escadron.
    * @param name Nouveau nom.
    */
   void setName(const std::string& name);

   /**
    * @brief Ajoute le vaisseau dans l'escadron.
    * @param leader Vaisseau à définir comme leader.
    * @details Si le vaisseau de fait pas partie de l'escadron
    *          la fonction est sans effet. Si nullptr, se comporte
    *          comme unsetLeader.
    */
   void setLeader(const Ship* leader);
   /**
    * @brief Retire le leader de l'escadron.
    * @details Si il n'est pas initialisée, la fonction est sans effet.
    */
   void unsetLeader();

   /**
    * @brief Calcule la consommation totale de l'escadron.
    * @param distance Distance à effectuer. (millions de kilomètres)
    * @return Retourne la consommation de l'escadron. (tonnes)
    */
   double consumption(double distance) const;


private:

   /**
    * @brief Initialise les attributs en arguments, réserve la capacité et
    *        définit la taille de l'escadron à 0.
    * @param name Nom de l'escadron.
    * @param capacity Capacité de l'escadron.
    * @param leader Leader de l'escadron.
    */
   void init(const std::string& name, size_t capacity, const Ship* leader);

   /**
    * @brief Copy l'escadron otherSquad dans l'escadron courrante.
    * @param otherSquad Escadron à copier.
    * @param otherSquadLength Taille de l'escadron à copier.
    * @throw out_of_range Si la capacité de l'escadron courrant est inférieur à l'escadron
    *                     à copier.
    */
   void copySquad(const Ship** otherSquad, size_t otherSquadLength);

   /**
    * @brief Double la capacité de l'escadron.
    */
   void increaseCapacity();

   /**
    * @brief Vérifie si le vaisseau est dans l'escadron.
    * @param ship Vaisseau à vérifier.
    * @return Retourne la position du vaisseau dans l'escadron si
    *         il s'y trouve sinon max de size_t.
    * @throw invalid_argument Si le pointeur ship est null.
    */
   size_t contains(const Ship* ship) const;

   /**
    * @brief Applique l'opération op sur l'escadron courrante.
    * @param ship Vaisseau concerné par l'opération.
    * @param op Opération à effectuer.
    * @return Retourne une référence sur l'escadron courrante avec l'opération
    *         appliquée.
    * @throw invalid_argument (levé par SquadronAdd/SquadronRemove)
    */
   Squadron& opSelf(const Ship* ship,const SquadronOperation& op);
   /**
    * @brief Applique l'opération op sur une copie de l'escadron.
    * @param ship Vaisseau concerné par l'opération.
    * @param op Opération à effectuer.
    * @return Retourne une copie de l'escadron avec l'opération
    *         appliquée.
    * @throw invalid_argument (levé par SquadronAdd/SquadronRemove)
    */
   Squadron  opCopy(const Ship* ship,const SquadronOperation& op) const;

   /**
    * @brief Libère l'espace mémoire alloué à la collection de vaisseaux.
    *        Initise squad à nullptr.
    */
   void freeSquad();

};


#endif //LABO2_SQUADRON_H
