/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : TIEIN.cpp
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 17/03/2021
 -----------------------------------------------------------------------------------
 */

#include "TIEIN.h"

unsigned TIEIN::count = 0;

TIEIN::TIEIN(const std::string& nickname)
        : super(++count, nickname)
{}

double TIEIN::getWeight() const
{
    return 5.0;
}

unsigned TIEIN::getSpeed() const
{
    return 110;
}

std::string TIEIN::getModel() const
{
    return "TIE/IN";
}
