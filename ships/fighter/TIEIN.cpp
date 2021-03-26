/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : TIEIN.cpp
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 17/03/2021
 -----------------------------------------------------------------------------------
 */

#include "TIEIN.h"

unsigned TIEIN::count = 0;
const double TIEIN::WEIGHT = 5.0;
const unsigned TIEIN::SPEED =  110;
const std::string TIEIN::MODEL = "TIE/IN";

TIEIN::TIEIN (const std::string &nickname)
        : super(++count, nickname)
{}

double TIEIN::getWeight () const
{
   return WEIGHT;
}

unsigned TIEIN::getSpeed () const
{
   return SPEED;
}

std::string TIEIN::getModel () const
{
   return MODEL;
}
