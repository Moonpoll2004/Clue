#ifndef CLUE_LIB_INCLUDE
#define CLUE_LIB_INCLUDE

#include <string>
#include <vector>
#include <WinBase.h>

namespace Clue
{
    
    enum class ClueTypes{
        BoolType = 0,
        StringType = 1,
        IntType = 2,
        NullType = 3
    };

    class Clue{
        private:
            
        public:
            std::vector<std::string> raw_args;
            char cwd[300];
            std::string filename;

        Clue(int argc,char * argv[])
        {
            for(int i= 0;i < argc; ++i){
                if(i == 0){
                    filename = argv[i];
                    continue;
                }
                raw_args.push_back(argv[i]);
            }

            GetCurrentDirectoryA(300,cwd);
        }
    };

    struct Arg{
        std::string name;
        std::string default_value;
        Clue * cli;
        ClueTypes type;

        Arg(const std::string& n,ClueTypes t,Clue &c)
        {
            name = n;
            type = t;
            cli = &c;
        }

        
        std::string Get() {
            if(type == ClueTypes::StringType){
                for(int i = 0 ;i<cli->raw_args.size();++i){
                    if(cli->raw_args[i] == name){
                        if(i+1 < cli->raw_args.size()){
                            return cli->raw_args[i+1];
                            break;
                        }
                    }
                }
                return "";
            } else {
                return "";
            }
        }

        bool GetBool(){
            if(type == ClueTypes::BoolType){
                for(int i=0;i<cli->raw_args.size();++i){
                    if(cli->raw_args[i] == name){
                        return true;
                    }
                }
                return false;
            }else{
                return 0;
            }
        }        

        int GetInt(){
            if(type == ClueTypes::IntType){
                for(int i=0;i<cli->raw_args.size();++i){
                    if(cli->raw_args[i] == name){
                        return std::stoi(cli->raw_args[i]);
                    }
                }
            }else{
                return 0;
            }
        }

        bool isNull(){
            return type == ClueTypes::NullType;
        }
    };
} // namespace Clue
#endif