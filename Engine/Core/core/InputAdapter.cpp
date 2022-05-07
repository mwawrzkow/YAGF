#include "InputAdapter.hpp"

namespace INPUT
{
    Adapter::Adapter()
    {
        for (auto k : KeyBoardKey)
        {
            keyPressed.insert(std::make_pair<KeyBoardKey, bool>(k, false));
            keyHold.insert(std::make_pair<KeyBoardKey, bool>(k, false));
        }
    }
    bool Adapter::isKeyPressed(KeyBoardKey k)
    {
        return keyPressed[k];
    }
    bool Adapter::isKeyHold(KeyBoardKey k)
    {
        return keyHold[k];
    }
    AdapterHandler::KeyActionType AdapterHandler::getAction()
    {
        return Action;
    }
    KeyBoardKey AdapterHandler::getKey()
    {
        return key;
    }
    AdapterHandler *AdapterHandler::getInstance()
    {
        static AdapterHandler Adapter;
        return &Adapter;
    }
    void AdapterHandler::onKeyUpdate(GLFWwindow *window, int key, int status, int action, int mods)
    {
        this = getInstance();
        switch (action)
        {
        case GLFW_PRESS:
            Action = Press_down;
            break;
        case GLFW_HOLD:
            Action = Hold;
        default:
            break;
        }
        updateKey(Key);
    }
    void AdapterHandler::UpdateKey(int Key)
    {
        switch (key)
        {
        case GLFW_KEY_W:
            Key = W;
            break;
        case GLFW_KEY_S:
            Key = S;
            break;
        case GLFW_KEY_D:
            Key = D;
            break;
        case GLFW_KEY_A:
            Key = A;
            break;
        default:
            break;
        }
    }

}

// class Adapter : public OSDL::Observer
//     {
//         std::map<KeyBoardKey, bool> keyPressed;
//         std::map<KeyBoardKey, bool> keyHold;

//     public:
//         void Notify(OSDL::Subject *);
//         bool isKeyPressed(KeyBoardKey);
//         bool isKeyHold(KeyBoardKey);
//     };
//     class AdapterHandler : public OSDL::Subject
//     {
//         AdapterHandler();

//     public:
//         enum KeyActionType
//         {
//             Hold,
//             Press_down,
//             Press_Up
//         };
//         AdapterHandler(AdapterHandler &other) = delete;
//         void operator=(const AdapterHandler &) = delete;
//         AdapterHandler *getInstance();
//         static void onKeyUpdate(GLFWwindow *window, int key, int status, int action, int mods);

//     private:
//         KeyBoardKey key;
//         KeyActionType Action;
//     public:
//         KeyBoardKey getKey();
//         KeyActionType getAction();
//     };