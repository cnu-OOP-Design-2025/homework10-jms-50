#include "MyVector.h"

template <typename T>
void MyVector<T>::push_back(const T &val)
{ // Vector 마지막에 항목을 추가하는 함수 구현, 필요시 벡터 크기 증가
    if (length == cap)
    {
        cap *= 2;
        T *newData = new T[cap];
        size_t i;
        for (i = 0; i < length; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[length++] = val;
}
template <typename T>
void MyVector<T>::pop_back()
{ // Vector의 마지막 항목을 제거하는 함수 구현
    this->length--;
}
template <typename T>
size_t MyVector<T>::size() const
{ // Vecotr에 있는 항목 개수(length)를 리턴하는 함수 구현
    return this->length;
}
template <typename T>
T& MyVector<T>::operator[](int i)
{
    return this->data[i];
}
template <typename T>
bool MyVector<T>::operator==(const MyVector& other) const
{
    size_t i;
    for (i = 0; i < length; i++)
    {
        if (this->data[i] != other.data[i])
        {
            return false;
        }
    }
    return true;
}
template <typename T>
bool MyVector<T>::operator!=(const MyVector& other) const
{
    size_t i;
    for (i = 0; i < length; i++){
        if (this->data[i] != other.data[i])
        {
            return true;
        }
    }
    return false;
}
template <typename T>
bool MyVector<T>::operator<(const MyVector& other) const
{
    if(length == other.length){
        size_t i;
        for(i = 0; i < length; i++){
            if(data[i] > other.data[i]){
                return false;
            }
            else if(data[i] < other.data[i]){
                return true;
            }
        }
    }
    return this->length < other.length;
}
template <typename T>
bool MyVector<T>::operator>(const MyVector& other) const
{
    if(length == other.length){
        size_t i;
        for(i = 0; i < length; i++){
            if(data[i] > other.data[i]){
                return true;
            }
            else if(data[i] < other.data[i]){
                return false;
            }
        }
    }
    return this->length > other.length;
}
template <typename T>
bool MyVector<T>::operator<=(const MyVector& other) const
{
    return this->length <= other.length;
}
template <typename T>
bool MyVector<T>::operator>=(const MyVector& other) const
{
    return this->length >= other.length;
}

template <typename T>
T& MyVector<T>::Iterator::operator*()
{
    return *ptr;
}

template <typename T>
typename MyVector<T>::Iterator& MyVector<T>::Iterator::operator++()
{
    ptr++;
    return *this;
}

template <typename T>
typename MyVector<T>::Iterator& MyVector<T>::Iterator::operator--()
{
    ptr--;
    return *this;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::Iterator::operator+(int n) const
{
    return Iterator(ptr + n);
}
template <typename T>
typename MyVector<T>::Iterator MyVector<T>::Iterator::operator-(int n) const
{
    return Iterator(ptr - n);
}

template <typename T>
bool MyVector<T>::Iterator::operator==(const Iterator& other) const
{
    return ptr == other.ptr;
}
template <typename T>
bool MyVector<T>::Iterator::operator!=(const Iterator& other) const
{
    return ptr != other.ptr;
}

template <typename T>
int MyVector<T>::Iterator::operator-(const Iterator& other) const
{
    return ptr - other.ptr;
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::begin()
{
    return Iterator(data);
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::end()
{
    return Iterator(data + length);
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::insert(Iterator pos, const T& value)
{
    size_t i;
 
    if (length == cap)
    {
        cap *= 2;
        T *newData = new T[cap];
        for (i = 0; i < length; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

    size_t pos_index = pos - this->begin();
    for (i = length; i > pos_index; i--) {
        data[i] = data[i - 1];
    }

    data[pos_index] = value;
    length++;

    return Iterator(data + pos_index);
}

template <typename T>
typename MyVector<T>::Iterator MyVector<T>::erase(Iterator pos)
{
    size_t i;
    size_t pos_index = pos - data;
    for (i = pos_index; i < length - 1; i++) {
        data[i] = data[i + 1];
    }

    length--;
    return Iterator(data+pos_index);
}

template <typename T>
void MyVector<T>::clear()
{
    length = 0;
}

// at: 범위 체크 후, i번째 항목 접근 함수 구현
template <typename T>
T &MyVector<T>::at(size_t i)
{
    if(0 <= i && i < length){
        return data[i];
    }
    return data[0];
}

// front/back
template <typename T>
T &MyVector<T>::front()
{
    return data[0];
} // 첫번째 항목 리턴 함수 구현
template <typename T>
T &MyVector<T>::back()
{ 
    return data[length-1];
} // 마지막 항목 리턴 함수 구현

template <typename T>
size_t MyVector<T>::capacity() const
{
    return cap;
} // cap 값 리턴하는 함수 구현

template <typename T>
bool MyVector<T>::empty() const
{
    return length == 0;
} // 현재 vector가 empty인지 확인하는 함수 구현


template class MyVector<int>;