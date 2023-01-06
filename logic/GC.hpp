#ifndef _GC
#define _GC

#include <iostream>
#include <vector>

using namespace std;

// Garbage Collector for the game
class GC {
    public:
        static void add(void* ptr);
        static void nettoie();
    private:
        static vector<void*> ptrs;
};



#endif