#ifndef ARRAYHANDLER_HPP
#define ARRAYHANDLER_HPP
#include <vector>
#include <utility>
namespace GPU
{
    class ArrayHandler;
    class GPU_Ref
    {
        unsigned int VAO, VBO, EBO;
        bool taken;

    protected:
        void Release();
        bool &Taken();
        GPU_Ref* Take(); 
    public:
        GPU_Ref(int, int, int);
        const unsigned int &getVAO();
        const unsigned int &getVBO();
        const unsigned int &getEBO();

        friend class ArrayHandler;
    };
    class ArrayHandler
    {
    private:
        std::vector<GPU_Ref> GPUSpace;
        /**
         * @brief  check if are repetitions in Array
         * @note   
         * @param int[]: array
         * @param  int: size of array 
         * @retval true: If they're repetiotion 
         * @retval false: if there are no repetitions
         */
        bool areRepetitions(unsigned int[], int);

    public:
        ArrayHandler(/* args */);
        /**
         * @brief  Check if any buffers are avaliable
         * @note   
         * @retval bool are any buffers free
         */
        bool areFreeBuffers();
        /**
         * @brief  Alocates GPU space for x buffers
         * @param int size amount of buffers
         * @note   
         * @retval bool if buffers were created
         */
        bool alocateBuffer(int);
        /**
        * @brief  Returns pointer to first Available Buffer
        * @note   
        * @retval GPU_Ref Pointer to buffer, in not buffers available return nullptr
        */
        GPU_Ref *getFirstAvailavleBuffer();
        /**
         * @brief  Releases the buffer, if buffer is not taken does nothing
         * @note 
         * @throws   
         * @retval None
         */
        void releaseBuffer(int);
        ~ArrayHandler();
    };
}
#endif
