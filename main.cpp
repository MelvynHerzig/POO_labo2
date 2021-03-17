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

int main ()
{
   TIE* blackLeader = new TIE();
   blackLeader->setNickname("Black leader");
   TIE* blackTwo = new TIE();
   Shuttle* shuttle = new Shuttle(23.4); // 23.4 tonnes de marchandises
   Squadron squad("Black Squadron");
   squad += blackLeader;
   squad += blackTwo;
   squad += shuttle;
   squad.setLeader(blackLeader);
   cout << squad << endl;
}
