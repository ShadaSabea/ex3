//
// Created by Shada Sabea on 24/05/2022.
//

#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H


template <class T>
class Queue
{

public:
    Queue();
//explicit Queue(const int size);
Queue(const Queue<T>& queue);
~Queue();
Queue& operator=(const Queue& queue);


void pushBack(T& element);

T& popFront();

int size();

template <class Condition>
Queue filter(Condition c) const;

void transform(Condition c) const;

class InvalidSize{};
//Queue<T>& operator!=




private:
    T* m_array;
    int m_size;
    static const int INITIAL_SIZE=1;

};





template<class T>
Queue<T>::Queue(): m_array(new T[INITIAL_SIZE]),
m_size(INITIAL_SIZE)
{}





template<class T>
Queue<T>::~Queue()
{
    delete[] m_array;
}


template<class T>
Queue<T>& Queue<T>::operator=(const Queue& queue)
{
    if(this==&queue)
    {
        return *this;
    }
    int size1=queue.size;
    T* temp_array=new T[size1];
    try {
        for (int i = 0; i < size1; i++) {
            temp_array[i] = queue.m_array[i];
        }
    }
    catch(...)
    {
    delete[] temp_array;
    throw;
    }
    delete[] m_array;
    m_array=temp_array;

    return *this;
}

template<class T>
Queue<T>::Queue(const Queue<T>& queue):
m_array(new T[queue.m_size]), m_size(queue.m_size)
{
    try {
        for (int i = 0; i < m_size; i++)
        {
            m_array[i] = queue.m_array[i];
        }
    }catch(...)
    {
        delete[] m_array;
        throw;
    }
}


template<class T>
void Queue<T>::pushBack(T& element)
{
    T* queue=new T[m_size+1];
try
{
    for (int i = 0; i < m_size; i++)
    {
        queue[i] = m_array[i];
    }
    queue[m_size]= element;
}
catch (...)
{
    delete[] queue;
    throw ;
}

delete[] m_array;
m_array=queue;
}



#endif //EX3_QUEUE_H
