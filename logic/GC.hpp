#ifndef _GC
#define _GC

#include <iostream>
#include <vector>

class GC {
    public:
        static void add(void* ptr);
        static void nettoie();
    private:
        static std::vector<void*> ptrs;
};

#endif