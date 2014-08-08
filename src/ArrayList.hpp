#ifndef __ARRAYLIST_HPP__
#define __ARRAYLIST_HPP__

#include <string>

template <typename T>
namespace
{
    const size_t START_SIZE = 16;
    void array_copy<T>(T *source, T *dest, size_t size)
    {
        for (int i = 0; i < size; i++) dest[i] = source[i];
    }
}

template <typename T>
class ArrayList
{
    public:
        ArrayList();
        ArrayList(size_t capacity);
        ArrayList(const ArrayList& other);
        ArrayList<T>& operator=(const ArrayList& other);
        ~ArrayList();
        T& at(size_t index);
        const T& at(size_t index) const;
        ArrayList<T>& push_back(T input);
        size_t size() const;
        size_t capacity() const;

    private:
        T *m_data;
        size_t m_size;
        size_t m_capacity;
};
    
#endif
