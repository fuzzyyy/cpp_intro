#ifndef LIB_ALGS_H
#define LIB_ALGS_H

#include <algorithm>

template<class InputIterator>
bool my_equal(InputIterator begin, InputIterator end, InputIterator dest)
{
    while ((begin != end) && (*begin++ == *dest++))
    {
    }

    return begin == end;
}

template<class InputIterator, class T>
InputIterator my_find(InputIterator begin, InputIterator end, const T& val)
{
    while (begin != end)
    {
        if (*begin == val)
        {
            return begin;
        }
        ++begin;
    }

    return end;
}

template<class InputIterator, class OutputIterator>
OutputIterator
my_copy(InputIterator begin, InputIterator end, OutputIterator dest)
{
    while (begin != end)
    {
        *dest++ = *begin++;
    }

    return dest;
}

template<class InputIterator, class OutputIterator, class Function>
OutputIterator my_remove_copy_if(InputIterator begin,
                                 InputIterator end,
                                 OutputIterator dest,
                                 Function predicate)
{
    while (begin != end)
    {
        if (!predicate(*begin))
        {
            *dest = *begin;
            ++dest;
        }
        ++begin;
    }

    return dest;
}

template<class InputIterator, class OutputIterator, class Function>
OutputIterator my_transform(InputIterator begin,
                            InputIterator end,
                            OutputIterator dest,
                            Function trans)
{
    while (begin != end)
    {
        *dest++ = trans(*begin++);
    }

    return dest;
}

template<class InputIterator, class OutputIterator, class T>
T my_accumulate(InputIterator begin, InputIterator end, T initval)
{
    while (begin != end)
    {
        initval += *begin++;
    }

    return initval;
}

template<class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 my_search(ForwardIterator1 begin1,
                           ForwardIterator1 end1,
                           ForwardIterator2 begin2,
                           ForwardIterator2 end2)
{
    while (begin1 != end1)
    {
        ForwardIterator1 iter1 = begin1;
        ForwardIterator2 iter2 = begin2;
        while (*iter1 == *iter2)
        {
            if (iter2 == end2)
            {
                return begin1;
            }
            if (iter1 == end1)
            {
                return end1;
            }
            ++iter1;
            ++iter2;
        }
        ++begin1;
    }

    return end1;
}

template<class InputIterator, class Function>
InputIterator
my_find_if(InputIterator begin, InputIterator end, Function predicate)
{
    while (begin != end)
    {
        if (predicate(*begin))
        {
            return begin;
        }
        ++begin;
    }

    return end;
}

template<class InputIterator, class OutputIterator, class T>
OutputIterator my_remove_copy(InputIterator begin,
                              InputIterator end,
                              OutputIterator dest,
                              const T& val)
{
    while (begin != end)
    {
        if (*begin != val)
        {
            *dest++ = *begin;
        }
        ++begin;
    }

    return dest;
}

template<class ForwardIterator, class T>
ForwardIterator
my_remove(ForwardIterator begin, ForwardIterator end, const T& val)
{
    ForwardIterator a = begin;
    while (a != end && *a != val)
    {
        ++a;
    }

    if (a == end)
    {
        return end;
    }

    ForwardIterator b = a;
    ++b;
    while (b != end)
    {
        if (*b != val)   // move the value
        {
            *a = *b;
            ++a;
        }
        ++b;
    }
    return a;
}

template<class BidirectionalIterator, class Function>
BidirectionalIterator my_partition(BidirectionalIterator begin,
                                   BidirectionalIterator end,
                                   Function predicate)
{
    // ^C^V from cplusplus.com
    while (begin != end)
    {
        while (predicate(*begin))
        {
            ++begin;
            if (begin == end)
                return begin;
        }
        do
        {
            --end;
            if (begin == end)
                return begin;
        } while (!pred(*end));
        std::swap(*begin, *end);
        ++begin;
    }
    return begin;
}

template<class T>
void my_swap(T& a, T& b)
{
    T c = a;
    a   = b;
    b   = c;
}

#endif
