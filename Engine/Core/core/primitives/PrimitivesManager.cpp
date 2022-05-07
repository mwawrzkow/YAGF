#include "PrimitivesManager.hpp"

namespace Primitives{ 
    //write all methods definied in PrimitivesManager.hpp
    PrimitivesManager::PrimitivesManager()
    {
        primitives = Primitives::Primitives();
    }
    void PrimitivesManager::addPrimitive(Primitive* primitive)
    {
        primitives.push_back(primitive);
    }
    void PrimitivesManager::removePrimitive(Primitive* primitive)
    {
        for(int i = 0; i < primitives.size(); i++)
        {
            if(primitives[i] == primitive)
            {
                primitives.erase(primitives.begin() + i);
            }
        }
    }
    void PrimitivesManager::removePrimitive(int index)
    {
        primitives.erase(primitives.begin() + index);
    }
    void PrimitivesManager::removeAllPrimitives()
    {
        primitives.clear();
    }
    void PrimitivesManager::DisplayAll()
    {
        for(int i = 0; i < primitives.size(); i++)
        {
            primitives[i]->Display();
        }
    }
    PrimitivesRef PrimitivesManager::getPrimitives()
    {
        return primitives;
    }
    //get primitives vector near to the given point
    Primitives PrimitivesManager::getPrimitivesNear(float x, float y, float radius)
    {
        Primitives nearPrimitives;
        for(int i = 0; i < primitives.size(); i++)
        {
            if(primitives[i]->isNear(x, y, radius))
            {
                nearPrimitives.push_back(primitives[i]);
            }
        }
        return nearPrimitives;
    }
    PrimitivesManager::~PrimitivesManager()
    {
        primitives.clear();
    }
}