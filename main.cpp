/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : main.cpp
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 17/03/2021

 But         : Tester l'utilisation de la classe Squadron.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include "ships/cargo/Shuttle.h"
#include "Squadron.h"
#include "ships/fighter/TIELN.h"

using namespace std;

int main()
{
    TIELN* blackLeader = new TIELN();
    blackLeader->setNickname("Black leader");
    TIELN* blackTwo = new TIELN();
    Shuttle* shuttle = new Shuttle(23.4); // 23.4 tonnes de marchandises
    Squadron squad("Black Squadron");
    squad += blackLeader;
    squad += blackTwo;
    squad += shuttle;
    squad.setLeader(blackLeader);
    cout << squad << endl;
}
