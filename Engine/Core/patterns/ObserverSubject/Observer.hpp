#ifndef OBSERVER_HPP
#define OBSERVER_HPP
#include "Subject.hpp"
namespace  OSDL { 
class Observer
{
private:    
public:
    Observer(/* args */);
    ~Observer();
    virtual void Notify(Subject*); 
};
}
#endif 