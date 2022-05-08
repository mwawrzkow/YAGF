#include "Subject.hpp"

namespace OSDL
{

    void Subject::addObserver(Observer &observer)
    {
        this->observers.push_back(&observer);
    }
    void Subject::Notify()
    {
        for (Observer *o : observers)
            o->Notify(this);
    }
    void Subject::NotifyObserver(Observer &o)
    {
        o.Notify(this);
    }
    void Subject::removeObserver(Observer &o)
    {
        for (int i = 0; i < observers.size(); i++)
        {
            if (observers[i] == &o)
            {
                observers.erase(observers.begin() + i, observers.begin() + i);
            }
        }
    }
}