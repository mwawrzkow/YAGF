#ifndef DUALLINK_HPP
#define DUALLINK_HPP
#include "Observer.hpp"
#include "Subject.hpp"
namespace  OSDL { 
class DualLink: public Observer, Subject
{
private:
    /* data */
public:
    DualLink(/* args */);
    ~DualLink();
};
}


#endif