#include "GC.hpp"

using namespace std;

vector<void*> GC::ptrs;

void GC::add(void* ptr) {
    ptrs.push_back(ptr);
}
void GC::nettoie() {    
    cout << "Vidage du Garbage Collector..." << endl;
    for (auto ptr : ptrs) {
        delete ptr;
    }
    cout << "Garbage Collector vidé." << endl;
}