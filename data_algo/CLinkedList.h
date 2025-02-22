#pragma once

#include <assert.h>

template <typename T>
class CListNode
{
    template <typename T>
    friend class CLinkedList;

    template <typename T>
    friend class CListIterator;

    template <typename T>
    friend class CListReverseIterator;

public:
    CListNode()
    {
        m_pNext = nullptr;
        m_pPrev = nullptr;
    }
    ~CListNode()
    {
    }

private:
    T               m_Data;
    CListNode<T>*   m_pNext;
    CListNode<T>*   m_pPrev;

};

template <typename T>
class CListIterator
{
    template <typename T>
    friend class CLinkedList;

public:
    CListIterator()
    {
        m_pNode = nullptr;
    }
    ~CListIterator()
    {

    }

private:
    typedef CListNode<T>*   PNODE;

private:
    PNODE m_pNode;

public:
    bool operator == (const CListIterator<T>& iter)
    {
        return m_pNode == iter.m_pNode;
    }
    bool operator != (const CListIterator<T>& iter)
    {
        return m_pNode != iter.m_pNode;
    }

    void operator ++()
    {
        m_pNode = m_pNode->m_pNext;
    }

    void operator -- ()
    {
        m_pNode = m_pNode->m_pPrev;
    }

    T& operator * ()
    {
        return m_pNode->m_Data;
    }

};


template <typename T>
class CLinkedList
{
private:
    typedef CListNode<T>    NODE;
    typedef CListNode<T>*   PNODE;

public:
    typedef CListIterator<T>    iterator;

private:
    PNODE   m_pBegin;
    PNODE   m_pEnd;
    int     m_iSize;

public:
    void push_back(const T& data)
    {
        PNODE pNode = new NODE;
        pNode->m_Data = data;

        // End 의 이전 노드를 저장
        PNODE pPrev = m_pEnd->m_pPrev;
        // 기존 마지막 노드의 Next 를 현재노드로 바꾸고, 현재노드의 이전 노드를 기존마지막노드로 교체
        pPrev->m_pNext = pNode;
        pNode->m_pPrev = pPrev;
        // End와 노드 연결
        pNode->m_pNext = m_pEnd;
        m_pEnd->m_pPrev = pNode;

        ++m_iSize;
    }

    void push_front(const T& data)
    {
        PNODE pNode = new NODE;
        pNode->m_Data = data;

        PNODE pBegin = m_pBegin->m_pNext;

        pBegin->m_pPrev = pNode;
        pNode->m_pNext = pBegin;

        pNode->m_pPrev = m_pBegin;
        m_pBegin->m_pNext = pNode;

        ++m_iSize;
    }

    // begin, end 제외한 실제 추가노드의 삭제 기능
    void clear()
    {
        PNODE pNode = m_pBegin->m_pNext;
        while (pNode != m_pEnd)
        {
            PNODE temp = pNode->m_pNext;

            delete pNode;

            pNode = temp;
        }
        m_iSize = 0;
        m_pBegin->m_pNext = m_pEnd;
        m_pEnd->m_pPrev = m_pBegin;
    }

    void pop_back()
    {
        if(empty())
            assert(false);
        
        PNODE temp = m_pEnd->m_pPrev;
        PNODE tempPrev = temp->m_pPrev;
        tempPrev->m_pNext = m_pEnd;
        m_pEnd->m_pPrev = tempPrev;
        delete temp;
        --m_iSize;
    }

    void pop_front()
    {
        if(empty())
            assert(false);
        
        PNODE temp = m_pBegin->m_pNext;
        PNODE tempNext = temp->m_pNext;
        tempNext->m_pPrev = m_pBegin;
        m_pBegin->m_pNext = tempNext;
        delete temp;
        --m_iSize;
    }
    
    T front()   const
    {
        if(empty())
            assert(false);
        return m_pBegin->m_pNext->m_Data;
    }

    T back()    const
    {
        if(empty())
            assert(false);
        return m_pEnd->m_pPrev->m_Data;
    }

    int size()  const
    {
        return m_iSize;
    }

    bool empty() const
    {
        return m_iSize == 0;
    }

public:
    CLinkedList()
    {
        m_pBegin = new NODE;
        m_pEnd = new NODE;

        m_pBegin->m_pNext = m_pEnd;
        m_pEnd->m_pPrev = m_pBegin;
        m_iSize = 0;
    }

    ~CLinkedList()
    {
        clear();
        delete m_pBegin;
        delete m_pEnd;
    }

public:
    // begin() 함수는 추가된 가장 첫번째 노드의 주소를 가지고있는 이터레이터를 반환한다.
    iterator begin()    const
    {
        iterator    iter;
        iter.m_pNode = m_pBegin->m_pNext;
        return iter;
    }

    iterator end()      const
    {
        iterator iter;
        iter.m_pNode = m_pEnd->m_pPrev;
        return iter;
    }

public:

    void sort(bool(*pFunc)(const T&, const T&))
    {
        for (PNODE pFirst = m_pBegin->m_pNext; pFirst != m_pEnd->m_pPrev; pFirst->m_pNext)
        {
            for (PNODE pSecond = pFirst->m_pNext; pSecond != m_pEnd; pSecond->m_pNext)
            {
                if(pFunc(pFirst->m_Data, pSecond->m_Data))
                {
                    T temp = pFirst->m_Data;
                    pFirst->m_Data = pSecond->m_Data;
                    pSecond->m_Data = temp;
                }
            }
        }
    }
};