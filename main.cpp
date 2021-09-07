#include <iostream>
#include "./Clue.hpp"

using Clue::ClueTypes;

int main (int argc,char * argv[])
{
	Clue::Clue cli(argc,argv);

	Clue::Arg name("--name",ClueTypes::StringType,cli);
	Clue::Arg ismale("--male",ClueTypes::BoolType,cli);
	Clue::Arg age("--age",ClueTypes::IntType,cli);

	std::cout << name.Get() << "\n";
	std::cout << ismale.GetBool() << "\n";
	std::cout << cli.filename << '\n';
	std::cout << cli.cwd << '\n';
	std::cout <<"end" << "\n";
	return 0;
}
