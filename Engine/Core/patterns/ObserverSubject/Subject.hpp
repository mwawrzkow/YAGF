#ifndef Subject_HPP
#define Subject_HPP
#include "Observer.hpp"
#include <vector>
namespace  OSDL { 
    class Subject { 
     private: 
     std::vector<Observer*> observers; 
     public: 
     void addObserver(Observer&);
     void Notify(); 
     void NotifyObserver(Observer&);
     void removeObserver(Observer&); 
};
}


#endif 