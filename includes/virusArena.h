#ifndef virusArena_hpp
#define virusArena_hpp

#include "Virus.h"

using namespace sf;
int createBackground(VertexArray& rVA, IntRect arena);

Virus* createHorde(int numVirus, IntRect arena);

#endif /* virusArena_hpp */

int main();
