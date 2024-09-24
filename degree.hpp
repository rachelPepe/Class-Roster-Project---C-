//
//  degree.hpp
//  Applications Project
//
//  Created by Rachel Pepe on 2/26/24.
//

#ifndef degree_hpp
#define degree_hpp

#include <stdio.h>
#include <string>
using namespace std;


enum DegreeProgram {SECURITY, NETWORK, SOFTWARE};
// Parallel array to assign string value to enum types.
static const string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE"};

#endif /* degree_hpp */
