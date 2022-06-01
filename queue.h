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
    Queue& operator=(const Queue<T>& queue);

    T& front();
    T& front() const;
    void pushBack(const T& element);

    void popFront();

    int size() const;

    // template <class Condition>
    //  friend Queue<T> filter(Queue<T> queue,Condition c) const;


    // template <class Condition>
    // friend void transform(Queue<T> queue,Condition c) const;

    class ConstIterator;
    ConstIterator begin() const;
    ConstIterator end() const;

    class Iterator;
    Iterator begin();
    Iterator end() ;

    class EmptyQueue{};


private:
    T* m_array;
    int m_size;
    static const int INITIAL_SIZE=1;
    static const int INITIALIZE_SIZE=0;

};

template<class T>
Queue<T>::Queue(): m_array(new T[INITIAL_SIZE]),
                   m_size(INITIALIZE_SIZE)
{}





template<class T>
Queue<T>::~Queue()
{
    delete[] m_array;
}


template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& queue)
{
    if(this==&queue)
    {
        return *this;
    }
    int size1=queue.m_size;

    T* temp_array=new T[size1];
    try {
        m_size=size1;
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
Queue<T>::Queue(const Queue<T>& queue)
{
    m_array= new T[queue.m_size];
    try {
        m_size=queue.m_size;
        for (int i = 0; i < m_size; ++i)
        {
            m_array[i] = queue.m_array[i];
        }

    }
    catch(...)
    {
        delete[] m_array;
        throw;
    }
}


template<class T>
void Queue<T>::pushBack(const T& element)
{
    try {
        if (m_size == 0) {
            m_array[0] = element;
            m_size++;
            return;
        }
    }
    catch (...)
    {
        throw ;
    }

    T* queue=new T[m_size+1];
    try
    {
        for (int i = 0; i < m_size; ++i)
        {
            queue[i] = m_array[i];
        }
        queue[m_size]= element;
        m_size++;
    }
    catch (...)
    {
        delete[] queue;
        throw ;
    }

    delete[] m_array;
    m_array=queue;
}

template<class T>
int Queue<T>::size() const
{
    if(m_size<0)
    {
        throw EmptyQueue();
    }
    return m_size;
}


template<class T>
T& Queue<T>::front()
{
    if(m_size>0)
    {
        return m_array[0];
    }
    else
    {
        throw EmptyQueue();
    }
}


template<class T>
T& Queue<T>::front() const
{
    if(m_size>0)
    {
        return m_array[0];
    }
    else
    {
        throw EmptyQueue();
    }
}


template<class T>
void Queue<T>::popFront()
{
    if(m_size<=0)
    {
        EmptyQueue e;
        throw EmptyQueue (e);
    }
    if(m_size == 1)
    {
        m_size = 0;
        return ; 
    }
    T* queue= new T[m_size-1];
    try
    {
        for (int i = 1; i < m_size; i++)
        {
            queue[i-1] = m_array[i];
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

template <class T>
class Queue<T>::ConstIterator {
public:
    const T &operator*() const;

    ConstIterator &operator++();

    ConstIterator operator++(int);

    bool operator==(const ConstIterator &it) const;

    bool operator!=(const ConstIterator &it) const;

    ConstIterator(const ConstIterator& it) = default;

    ConstIterator &operator=(const ConstIterator& it) = default;

    class InvalidOperation{};


private:
    const Queue<T> *queue;
    int m_index;

    ConstIterator(const Queue<T>* queue, int index);

    friend class Queue<T>;
};

template <class T>
class Queue<T>::Iterator {
public:
    T& operator*() const;

    Iterator &operator++();

    Iterator operator++(int);


    bool operator==(const Iterator &it);


    bool operator!=(const Iterator &it);

    Iterator(const Iterator &it) = default;

    Iterator &operator=(const Iterator &it) = default;

    class InvalidOperation{};


private:
    const Queue<T> *queue;
    int m_index;

    Iterator(const Queue<T>* queue, int index);

    friend class Queue<T>;
};


template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
    return ConstIterator(this,0);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
    return Iterator(this,0);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
    return ConstIterator(this,m_size);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end()
{
    return Iterator(this,m_size);
}

template<class T>
bool Queue<T>::ConstIterator::operator==(const ConstIterator &it) const
{
    return m_index==it.m_index;
}

template<class T>
bool Queue<T>::Iterator::operator==(const Iterator &it)
{
    return m_index==it.m_index;
}

template<class T>
const T& Queue<T>::ConstIterator::operator*() const
{
    if(m_index<0|| m_index >= queue->m_size)
    {
        EmptyQueue e;
        throw EmptyQueue(e);
    }
    return queue->m_array[m_index];
}


template<class T>
T& Queue<T>::Iterator::operator*() const
{
    if(m_index<0|| m_index >= queue->m_size)
    {
        EmptyQueue e;
        throw EmptyQueue(e);
    }
    return queue->m_array[m_index];
}


template<class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& it) const
{
    return !(*this == it);
}

template<class T>
bool Queue<T>::Iterator::operator!=(const Iterator& it)
{
    return !(*this == it);
}




template <class T>
typename Queue<T>::Iterator&  Queue<T>::Iterator::operator++()
{
    if(m_index >= (queue->size()) || m_index<0 )
    {
        InvalidOperation e;
        throw InvalidOperation(e);
    }
    ++m_index;
    return *this;
}

template <class T>
typename Queue<T>::ConstIterator&  Queue<T>::ConstIterator::operator++()
{
    if(m_index >= (queue->size()) || m_index<0 )
    {
        InvalidOperation e;
        throw InvalidOperation(e);
    }
    ++m_index;
    return *this;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int)
{  /*if((queue->size())== m_index)
    {
        InvalidOperation e;
        throw InvalidOperation(e);
    }*/
    Iterator result=*this;
    ++*this;
    return result;
}


template <class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int)
{  /*if((queue->size())== m_index)
    {
        InvalidOperation e;
        throw InvalidOperation(e);
    }*/
    Iterator result=*this;
    ++*this;
    return result;
}

template <class T>
Queue<T>::Iterator::Iterator(const Queue<T>* queue,int index) :
        queue(queue)
{
    if(index<0)
    {   InvalidOperation e;
        throw InvalidOperation(e);
    }
    m_index=index;
}


template <class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T>* queue,int index) :
        queue(queue)
{
    if(index<0)
    {   InvalidOperation e;
        throw InvalidOperation(e);
    }
    m_index=index;
}


/*
template < class Condition, class T>
void transform(Queue<T>& queue , Condition c)
{
    for(T elem : queue)
    {
        c(elem);
    }
}

*/
template<class T, class Function>
void transform(Queue<T>& queue, Function c)
{

    for (auto iterator = queue.begin(); iterator != queue.end(); ++iterator)
    {
        c(*iterator);
    }

}

template < class Condition, class T>
Queue<T> filter(Queue<T> queue, Condition c)
{
    Queue<T> queue1;
    for(T elem : queue)
    {
        if(c(elem))
        {
            try {
                {
                    queue1.pushBack(elem);

                }
            } catch ( ...) {
                throw;
            }
        }
    }
    return queue1;
}

#endif //EX3_QUEUE_H
