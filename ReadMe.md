## Clue Cli-framework

Clue is a hight performance cli framework for c++.It aims to provide very simple syntax and fast coding.

### Features
* header only with no extra dependencies
* very simple to use
* dynamic memory allocation (stack allocation)

### Examples 
```cpp
#include <iostream>
#include ".path/to/Clue.hpp"

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
	re
```

* you can check the ```test``` folder for more information.