/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : TIELN.cpp
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 17/03/2021
 -----------------------------------------------------------------------------------
 */

#include "TIELN.h"

unsigned TIELN::count = 0;
const double TIELN::WEIGHT = 6;
const unsigned TIELN::SPEED = 100;
const std::string TIELN::MODEL = "TIE/LN";

TIELN::TIELN (const std::string &nickname)
        : super(++count, nickname)
{}

double TIELN::getWeight () const
{
   return WEIGHT;
}

unsigned TIELN::getSpeed () const
{
   return SPEED;
}

std::string TIELN::getModel () const
{
   return MODEL;
}
