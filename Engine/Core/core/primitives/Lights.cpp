#include "Lights.hpp"
namespace Lights{ 
    //write all methods definied in Lights.hpp
    LightManager::LightManager()
    {
        this->sphericalLights = std::vector<SphericalLight*>();
        this->directLights = std::vector<DirectLight*>();
        this->globalLights = std::vector<GlobalLight*>();
    }
    void LightManager::addDirectLight(DirectLight* directLight)
    {
        this->directLights.push_back(directLight);
    }
    void LightManager::addSphericalLight(SphericalLight* sphericalLight)
    {
        this->sphericalLights.push_back(sphericalLight);
    }
    void LightManager::addGlobalLight(GlobalLight* globalLight)
    {
        this->globalLights.push_back(globalLight);
    }
    void LightManager::removeDirectLight(DirectLight* directLight)
    {
        for(int i = 0; i < this->directLights.size(); i++)
        {
            if(this->directLights[i] == directLight)
            {
                this->directLights.erase(this->directLights.begin() + i);
            }
        }
    }
    void LightManager::removeSphericalLight(SphericalLight* sphericalLight)
    {
        for(int i = 0; i < this->sphericalLights.size(); i++)
        {
            if(this->sphericalLights[i] == sphericalLight)
            {
                this->sphericalLights.erase(this->sphericalLights.begin() + i);
            }
        }
    }
    void LightManager::removeGlobalLight(GlobalLight* globalLight)
    {
        for(int i = 0; i < this->globalLights.size(); i++)
        {
            if(this->globalLights[i] == globalLight)
            {
                this->globalLights.erase(this->globalLights.begin() + i);
            }
        }
    }
    void LightManager::addDirectLight(float x, float y, float z, float r, float g, float b, float a, float intensity, float angle)
    {
        DirectLight* directLight = new DirectLight(x, y, z, r, g, b, a, intensity, angle);
        this->directLights.push_back(directLight);
    }
    void LightManager::addSphericalLight(float x, float y, float z, float r, float g, float b, float a)
    {
        SphericalLight* sphericalLight = new SphericalLight(x, y, z, r, g, b, a);
        this->sphericalLights.push_back(sphericalLight);
    }
    void LightManager::addGlobalLight(float r, float g, float b, float a, float intensity)
    {
        GlobalLight* globalLight = new GlobalLight(r, g, b, a, intensity);
        this->globalLights.push_back(globalLight);
    }
    void LightManager::removeDirectLight(int index)
    {
        this->directLights.erase(this->directLights.begin() + index);
    }
    void LightManager::removeSphericalLight(int index)
    {
        this->sphericalLights.erase(this->sphericalLights.begin() + index);
    }
    void LightManager::removeGlobalLight(int index)
    {
        this->globalLights.erase(this->globalLights.begin() + index);
    }
    void LightManager::draw(Primitives::PrimitivesManager primitives)
    {
        this->drawDirectLights(primitives);
        this->drawSphericalLights(primitives);
        this->drawGlobalLights(primitives);
    }
    void LightManager::drawDirectLights(Primitives::PrimitivesManager primitives)
    {
        for(int i = 0; i < this->directLights.size(); i++)
        {
            DirectLight* light = this->directLights[i];
            //get the light's position
            float x = light->getX();
            float y = light->getY();
            //get the light's color in array from getters
            float r = light->getR();
            float g = light->getG();
            float b = light->getB();
            float a = light->getAlpha();
            //get the light's intensity
            float intensity = light->getLumen();
            //get the light's angle
            float angle = light->getConeAngle();
            //get the light's radius
            float radius = light->getConeWidth();
            //get the light's height
            float height = light->getConeLength();
            //get all primitives near the light
            Primitives::Primitives primitivesNearLight = primitives.getPrimitivesNear(x, y, radius);
            //draw the light
            //cast the light
            
        }
    }
    void LightManager::drawSphericalLights(Primitives::PrimitivesManager primitives)
    {
        throw "Not implemented";
    }
    void LightManager::drawGlobalLights(Primitives::PrimitivesManager primitives)
    {
        throw "Not implemented";
    }
    LightManager::~LightManager()
    {
        for(int i = 0; i < this->directLights.size(); i++)
        {
            delete this->directLights[i];
        }
        for(int i = 0; i < this->sphericalLights.size(); i++)
        {
            delete this->sphericalLights[i];
        }
        for(int i = 0; i < this->globalLights.size(); i++)
        {
            delete this->globalLights[i];
        }
    }
}