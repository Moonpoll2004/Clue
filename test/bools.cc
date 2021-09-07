/*
COPY RIGHT Of Clue framwork
Author Moonpoll2004
*/

#include "../Clue.hpp"
#include <iostream>

using Clue::ClueTypes;

int main(int argc,char * argv[])
{
    //Clue Cli Application
    Clue::Clue cli(argc,argv);

    //Clue Super Arguments
    Clue::Arg meel("--meel",ClueTypes::StringType,cli);
    Clue::Arg with_juice("--with-juice",ClueTypes::BoolType,cli);
    Clue::Arg with_souce("--with-souce",ClueTypes::BoolType,cli);

    std::string m = meel.Get();
    if(m.size() == 0){
        std::cout << "Where is your meel ?" << "\n";
        return 0 ;
    } else {
        std::cout << "Your meel is: "<< m << '\n';
    }

    if(with_juice.GetBool() == true){
        std::cout << "Nice choice with juice hah" << '\n';
    }

    if(with_souce.GetBool() == true){
        std::cout << "I think you love souce" << '\n'; 
    }

}