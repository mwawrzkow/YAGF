//Declare primitives manager in namespace Primitives
#include "../base/Primitive.hpp"

namespace Primitives
{
    typedef Primitive* PrimitivePtr;
    typedef std::vector<PrimitivePtr> Primitives;
    //reference to primitives vector
    typedef Primitives& PrimitivesRef;
    class PrimitivesManager
    {
    private:
        Primitives primitives;
    public:
        PrimitivesManager();
        void addPrimitive(Primitive*);
        void removePrimitive(Primitive*);
        void removePrimitive(int);
        void removeAllPrimitives();
        void DisplayAll();
        PrimitivesRef getPrimitives();
        //get primitives vector near to the given point
        Primitives getPrimitivesNear(float, float, float);
        ~PrimitivesManager();
    };
}