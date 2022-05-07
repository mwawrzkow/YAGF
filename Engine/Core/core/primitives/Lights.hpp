#include "Light/DirectLight.hpp"
#include "Light/GlobalLight.hpp"
#include "Light/SphericalLight.hpp"
#include <vector>
#include "PrimitivesManager.hpp"
namespace Lights{
    //Create class which holds all light sources
    class LightManager
    {
    private:
        std::vector<DirectLight*> directLights;
        std::vector<SphericalLight*> sphericalLights;
        std::vector<GlobalLight*> globalLights;
    public:
        LightManager();
        ~LightManager();
        void addDirectLight(DirectLight*);
        void addSphericalLight(SphericalLight*);
        void addGlobalLight(GlobalLight*);
        void removeDirectLight(DirectLight*);
        void removeSphericalLight(SphericalLight*);
        void removeGlobalLight(GlobalLight*);
        void addDirectLight(float, float, float, float, float, float, float, float, float);
        void addSphericalLight(float, float, float, float, float, float, float);
        void addGlobalLight(float, float, float, float, float, float, float);
        void draw(Primitives::PrimitivesManager primitives);
        private: 
        void drawDirectLights(Primitives::PrimitivesManager primitives);
        void drawSphericalLights(Primitives::PrimitivesManager primitives);
        void drawGlobalLights(Primitives::PrimitivesManager primitives);
    };
}