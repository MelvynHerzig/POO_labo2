/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : TIELN.cpp
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 17/03/2021
 -----------------------------------------------------------------------------------
 */
#include "TIELN.h"

unsigned TIELN::count = 0;

TIELN::TIELN(const std::string& nickname)
        : super(++count, nickname)
{}

double TIELN::getWeight() const
{
    return 6;
}

unsigned TIELN::getSpeed() const
{
    return 100;
}

std::string TIELN::getModel() const
{
    return "TIE/LN";
}
