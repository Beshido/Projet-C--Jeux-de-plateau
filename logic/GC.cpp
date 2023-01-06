#include "GC.hpp"

std::vector<void*> GC::ptrs;

void GC::add(void* ptr) {
    std::cout << "Ajout de " << ptr << " au Garbage Collector." << std::endl;
    ptrs.push_back(ptr);
}

void GC::nettoie() {    
    std::cout << "Vidage du Garbage Collector..." << std::endl;
    for (auto ptr : ptrs) {
        std::cout << "Suppression de " << ptr << " du Garbage Collector." << std::endl;
        delete ptr;
    }
    ptrs.clear();
    std::cout << "Garbage Collector vidé." << std::endl;
}