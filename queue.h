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
T& front();
void popFront();
int size();

template <class Condition>
Queue<T> filter(Queue<T> queue,Condition c) const;

template <class Condition>
void transform(Condition c) const;


class InvalidSize{};
class EmptyQueue{};


class Iterator;
    Iterator begin() const;
    Iterator end() const;




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
m_size++;
}

template<class T>
void Queue<T>::popFront()
 {
    if(m_size==0)
    {   EmptyQueue e;
        throw EmptyQueue (e);
    }


     T* queue=new T[m_size-1];
     try
     {
         for (int i = 0; i < m_size-1; i++)
         {
             queue[i] = m_array[i+1];
         }
     }
     catch (...)
     {
         delete[] queue;
         throw ;
     }
     delete [] m_array;
     m_array=queue;
     m_size--;
 }

template<class T>
template <class Condition>
Queue<T> Queue<T>::filter(Queue<T> queue, Condition c) const
{  Queue<T> queue1;

    for(int i=0;i<queue.m_size;i++)
    {
        if(c(queue.m_array[i]))
        {
            queue1.pushBack(queue.m_array[i]);
        }
    }
    return queue1;
}



template<class T>
int Queue<T>::size(){
    return m_size;
}


template<class T>
T& Queue<T>::front()
{
    if(m_size!=0)
    {
        return m_array[0];
    }
    else
    {
        EmptyQueue e;
        throw EmptyQueue(e);
    }
}

template<class T>
template <class Condition>
void Queue<T>::transform(Queue<T> queue,Condition c) const
{
    for (int i = 0; i < queue.m_size; ++i)
    {
        c(queue.m_array[i]);
    }
}



template <class T>
class Queue<T>::Iterator{
    public:
            const T& operator*() const;
            Iterator& operator++();
            Iterator operator++(T);
            bool operator==(const Iterator& it) const;
            bool operator!=(const Iterator& it) const;
            Iterator(const Iterator&)=default;
            Iterator& operator=(const Iterator&)=default;


    private:
            const Queue<T>* queue;
            int index;
            Iterator(const Queue<T> queue,int index);
            friend class Queue<T>;
        };



















#endif //EX3_QUEUE_H
