#ifndef INPUT_ADAPTER_HPP
#define INPUT_ADAPTER_HPP
#include "../patterns/ObserverSubject/DualLink.hpp"
#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
namespace INPUT
{
    enum KeyBoardKey
    {
        ERROR = -1,
        Key_1 = 0,
        Key_2,
        Key_3,
        Key_4,
        Key_5,
        Key_6,
        Key_7,
        Key_8,
        Key_9,
        Key_0,
        Q,
        W,
        E,
        R,
        T,
        Y,
        U,
        I,
        O,
        P,
        A,
        S,
        D,
        F,
        G,
        H,
        J,
        K,
        L,
        Z,
        X,
        C,
        V,
        B,
        N,
        M,
        Arrow_Up,
        Arrow_Down,
        Arrow_Left,
        Arrow_Right
    };
    class Adapter : public OSDL::Observer
    {
        std::map<KeyBoardKey, bool> keyPressed;
        std::map<KeyBoardKey, bool> keyHold;

    public:
        Adapter();
        void Notify(OSDL::Subject *);
        bool isKeyPressed(KeyBoardKey);
        bool isKeyHold(KeyBoardKey);
    };
    class AdapterHandler : public OSDL::Subject
    {
        AdapterHandler();

    public:
        enum KeyActionType
        {
            Hold,
            Press_down,
            Press_Up
        };
        AdapterHandler(AdapterHandler &other) = delete;
        void operator=(const AdapterHandler &) = delete;
        AdapterHandler *getInstance();
        static void onKeyUpdate(GLFWwindow *window, int key, int status, int action, int mods);

    private:
        void UpdateKey(int); 
        KeyBoardKey key;
        KeyActionType Action;
    public: 
        KeyBoardKey getKey(); 
        KeyActionType getAction(); 
    };

}

#endif