#include <cassert>
#include "ArrayList.hpp"

// Private functions in an un-named namespace

template <typename T>
ArrayList<T>::ArrayList()
    : m_data(nullptr)
    , m_size(0)
    , m_capacity(0)
{
    m_data = new T[START_SIZE];
    m_capacity = START_SIZE;
}

template <typename T>
ArrayList<T>::ArrayList(size_t capacity)
    : m_data(nullptr)
    , m_size(0)
    , m_capacity(capacity)
{
    m_data = new T[m_capacity];
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& other)
    : m_data(nullptr)
    , m_size(other.m_size)
    , m_capacity(other.m_capacity)
{
    m_data = new T[m_capacity];
    array_copy(other.m_data, m_data, m_capacity);
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    delete[] m_data;
}

template <typename T>
T& ArrayList<T>::operator=(const ArrayList<T>& other)
{
    if (this != &other)
    {
        delete[] m_data;
        m_size = other.m_size;
        m_capacity = other.m_capacity;

        m_data = new T[m_capacity];
        array_copy(other.m_data, m_data, m_size);
    }
    return *this;
}

template <typename T>
T& ArrayList<T>::at(size_t index)
{
    if(index < m_size)
    {
        throw std::out_of_range("The array went out of range");
    }
    return m_data[index];
}

template <typename T>
const T& ArrayList<T>::at(size_t index) const
{
    if(index < m_size)
    {
        throw std::out_of_range("The array went out of range");
    }
    return m_data[index];
}

template <typename T>
T& ArrayList<T>::push_back(T input)
{
    assert(m_size <= m_capacity);
    if (m_size == m_capacity)
    {
        m_capacity *= 2;
        T *new_data = new T[m_capacity];
        array_copy(m_data, new_data, m_size);
        delete[] m_data;
        m_data = new_data;
        new_data = nullptr;
    }
    m_data[m_size] = input;
    m_size++;
    return *this;
}

template <typename T>
size_t ArrayList<T>::size() const
{
    return m_size;
}

template <typename T>
size_t ArrayList<T>::capacity() const
{
    return m_capacity;
}

