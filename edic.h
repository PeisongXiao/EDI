#pragma once
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <utility>

//Evolving Design Interpreter Compiler
//EDIL Version:       0.1 alpha (2020.3)
//Compiler Version:   0.1 alpha (2020.3)
//This is the property of Peisong Xiao
//For problems and discussions, contact peisongxiao@outlook.com or peisong.xiao.xps@gmail.com
//If you have new ideas or improvements on the code, I'll be happy to know

#ifndef nullptr //Just in case you get the error about nullptr being undefined
#define nullptr 0
#endif

#ifndef EDIC_MACROS
#define EDIC_MACROS
//This would be where you define macros
#else
#error EDIC_MACROS pre-defined somewhere, please check it out
#endif //EDIC_MACROS

//I defined this type because I don't want the '>' of std::pair and std::vector
//To join together under formatting and cause compiler errors
//If you're not bothered by this problem, you could always replace them with the std::pair version
typedef std::pair<int, std::string> objName;

//This is the Read function that takes a look at the file, checks for errors, and list out the names
//You'll need to pass a file pointer with the "r" option and a vector's pointer for the result
//Returns an empty string if no error occurs
//If there happens to be an error, it would return the message
std::string Read(FILE *src, std::vector<objName> *nameList);

//This would be the compile funtion where all the magic happens
//You will need to pass a file pointer with the "r" option
//And another one with the "wb" option and the nameList result of the Read function
void Compile(FILE *src, FILE *dest, std::vector<std::string> nameList);

//Note: this compiler will have backwards compatibility in the future when it actually has multiple versions
//Which would be the function Upgrade(versionSrc, versionDest)

//The Reader struct
struct Reader
{
    objName obj;
    //You'll need to use a cast to actually get the value out
    void *val;
};

//The rest of the code(implmentations) are in the edic.cpp file