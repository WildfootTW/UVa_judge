/*
 * Version 
 * Author: WildfootW
 * GitHub: github.com/WildfootW
 * Copyright (C) 2019 WildfootW All rights reserved.
 *
 */

// Accepted

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>

#define INF 2147483647
#define EPS 1e-9
#define DEFAULT_FIXSTR 3
#define NDEBUG

using namespace std;

/* code start here */

#ifndef MY_HASH_SET_H
#define MY_HASH_SET_H

#include <vector>

using namespace std;

//---------------------
// Define HashSet class
//---------------------
// To use HashSet ADT,
// the class "Data" should at least overload the "()" and "==" operators.
//
// "size_t operator()" is to generate the hash key
// that will be % by _bucket_num to get the bucket number.
// ==> See "belong_bucket_num()"
//
// "bool operator==" is to identify two "Data" are the same
// it will be used to check whether there has already an equivalent "Data" object in the HashSet.
// Note that HashSet does not allow equivalent nodes to be inserted
//
template <class Data>
class HashSet
{
    using hash_bucket = vector<Data>;

public:
    HashSet(size_t b = 0) : _bucket_num(0), _buckets(NULL) { if(b != 0) init(b); }
    ~HashSet() { reset(); }

    // o An iterator should be able to go through all the valid Data
    //   in the Hash
    // o Functions to be implemented:
    //   - constructor(s), destructor
    //   - operator '*': return the HashNode
    //   - ++/--iterator, iterator++/--
    //   - operators '=', '==', !="
    //
    class iterator
    {
        friend class HashSet<Data>;
    public:
        iterator(): _hash_set(NULL), _bucket_index(0), _pos(0) {}
        iterator(const HashSet<Data>* _hash_set, size_t _bucket_index, size_t _pos): _hash_set(const_cast<HashSet<Data>*>(_hash_set)), _bucket_index(_bucket_index), _pos(_pos) {}

        const Data& operator * () const { return (*_hash_set)[_bucket_index][_pos]; }
        iterator& operator ++ () // no matter the iterator is_valid now, go to next valid data
        {
            ++_pos;
            while(_bucket_index < _hash_set->_bucket_num)
            {
                if(is_valid())
                    break;
                ++_bucket_index; _pos = 0;
            }
            return (*this);
        }
        iterator operator ++ (int) { iterator ret(*this); ++(*this); return ret; }
        iterator& operator -- () // no matter the iterator is_valid now, go to prev valid data
        {
            if(!is_valid()) // make sure the following code would not crash
            {
                if(_bucket_index >= _hash_set->_bucket_num)
                    _bucket_index = _hash_set->_bucket_num - 1;
                _pos = (*_hash_set)[_bucket_index].size();
            }

            while(true)
            {
                if(_pos != 0) { --_pos; break; }
                if(_bucket_index == 0) { (*this) = _hash_set->end(); break; }
                --_bucket_index;
                _pos = (*_hash_set)[_bucket_index].size();
            }
            return (*this);
        }
        iterator operator -- (int) { iterator ret(*this); --(*this); return ret; }

        bool operator == (const iterator& i) const { return (_hash_set == i._hash_set && _bucket_index == i._bucket_index && _pos == i._pos); }
        bool operator != (const iterator& i) const { return !((*this) == i); }

        bool is_valid() const
        {
            if(_bucket_index < _hash_set->_bucket_num)
                return (*_hash_set)[_bucket_index].size() > _pos;
            return false;
        }

    private:
        HashSet* _hash_set;
        size_t _bucket_index;
        size_t _pos;
    };

    void init(size_t b) { _bucket_num = b; _buckets = new hash_bucket[b]; }
    void reset()
    {
       _bucket_num = 0;
       if(_buckets) { delete [] _buckets; _buckets = 0; }
    }
    void clear() { for(size_t i = 0; i < _bucket_num; ++i) { _buckets[i].clear(); } }
    size_t numBuckets() const { return _bucket_num; }

    hash_bucket& operator [] (size_t i) { return _buckets[i]; }
    const hash_bucket& operator [] (size_t i) const { return _buckets[i]; }

    // Point to the first valid data
    iterator begin() const
    {
        iterator ret(this, 0, 0);
        if(ret.is_valid())
            return ret;
        return ++ret;
    }
    // Pass the end
    iterator end() const { return iterator(this, _bucket_num, 0); }
    // return true if no valid data
    bool empty() const { return begin() == end(); }
    // number of valid data
    size_t size() const
    {
        size_t count = 0;
        for(iterator i = begin();i != end();++i)
            ++count;
        return count;
    }

    // return iterator where Data equal d(d.operator==)
    // return end() if not found
    iterator find(const Data& d) const
    {
        size_t _bucket_index = belong_bucket_num(d);
        for(size_t _pos = 0;_pos < _buckets[_bucket_index].size();++_pos)
        {
            if(_buckets[_bucket_index][_pos] == d)
            {
#ifndef NDEBUG
                cout << "duplicatie: " << endl;;
                _buckets[_bucket_index][_pos].print_data();
                d.print_data();
                cout << "====" << endl;
#endif // NDEBUG
                return iterator(this, _bucket_index, _pos);
            }
        }
        return end();
    }

    // erase the Data which pointed by "it"
    // return false while "it" is not valid
    // [note] other exist iterator could be affect by this function
    bool erase(const iterator& it)
    {
        if(!it.is_valid())
            return false;
        _buckets[it._bucket_index].erase(_buckets[it._bucket_index].begin() + it._pos);
        return true;
    }

    // check if d is in the HashSet
    bool check(const Data& d) const
    {
        return !(find(d) == end());
    }

    // return true if inserted successfully (i.e. d is not in the hash)
    // return false is d is already in the hash ==> will not insert
    bool insert(const Data& d)
    {
        if(check(d))
            return false;
        _buckets[belong_bucket_num(d)].push_back(d);
        return true;
    }

    // query if d is in the hash... (d.operator==)
    // if yes, replace d with the data in the hash and return true;
    // else return false;
    bool query(Data& d) const
    {
        iterator it = find(d);
        if(it == end())
            return false;
        d = *it;
        return true;
    }

    // return true if removed successfully (i.e. d is in the hash)
    // return false otherwise (i.e. nothing is removed)
    bool remove(const Data& d)
    {
        iterator it = find(d);
        if(it == end())
            return false;
        return erase(it);
    }

    // update the entry in hash that is equal to d (i.e. == return true)
    // if found, update that entry with d and return true;
    // else insert d into hash as a new entry and return false;
    // [note] kind of strange function
    bool update(const Data& d)
    {
        iterator it = find(d);
        if(it == end())
        {
            insert(d);
            return false;
        }
        return replace(it, d);
    }
    bool replace(const iterator& it, const Data& d)
    {
        if(!it.is_valid())
            return false;
        assert(it._bucket_index == belong_bucket_num(d)); // if it is not equal, we can't "find" this Data forever

        _buckets[it._bucket_index][it._pos] = d;
        return true;
    }

#ifndef NDEBUG
    void print_all_in_hash() const
    {
        cout << "==========begin==========" << endl;
        for(iterator it = begin();it != end();++it)
            (*it).print_data();
        cout << "===========end===========" << endl;
    }
#endif // NDEBUG

private:
    // Do not add any extra data member
    size_t          _bucket_num;
    hash_bucket*    _buckets;          // end() => _buckets[_bucket_num][0]

    inline size_t belong_bucket_num(const Data& d) const
    {
        assert(_bucket_num != 0); // remember init
        return (d() % _bucket_num);
    }
};

#endif // MY_HASH_SET_H

class n_tuple
{
public:
    n_tuple(size_t n): _num(n) { _arr = new unsigned int[_num]; }
    n_tuple(const n_tuple& e): _num(e._num) { _arr = new unsigned int[_num]; memcpy(_arr, e._arr, sizeof(unsigned int) * _num); }
    ~n_tuple() { delete [] _arr; }

    const n_tuple& operator = (const n_tuple& e)
    {
        if(this == &e) return *this;

        delete [] _arr;
        _num = e._num;
        _arr = new unsigned int[e._num];

        for(size_t i = 0;i < _num;++i)
            _arr[i] = e._arr[i];
        memcpy(_arr, e._arr, sizeof(unsigned int) * _num);
        return *this;
    }

    bool operator == (const n_tuple& e) const
    {
        if(_num != e._num)
            return false;
        for(size_t i = 0;i < _num;++i)
        {
            if(_arr[i] != e._arr[i])
                return false;
        }
        return true;
    }

    unsigned int operator () () const // hash
    {
        unsigned int ret = 0;
        for(size_t i = 0;i < _num;++i)
            ret += (_arr[i] * (i + 1));
        return ret;
    }

    bool is_all_zero() const
    {
        for(size_t i = 0;i < _num;++i)
        {
            if(_arr[i] != 0)
                return false;
        }
        return true;
    }

    bool set(const size_t& n, const unsigned int& d)
    {
        if(!(n < _num))
            return false;
        _arr[n] = d;
        return true;
    }

    n_tuple next_step() const
    {
        n_tuple ret(_num);
        ret.set(_num - 1, abs(int(_arr[0] - _arr[_num - 1])));
        for(size_t i = 0;i < _num - 1;++i)
        {
            ret.set(i, abs(int(_arr[i] - _arr[i + 1])));
        }
        return ret;
    }

    void to_next_step()
    {
        (*this) = next_step();
    }

#ifndef NDEBUG
    void print_data() const
    {
        for(size_t i = 0;i < _num;++i)
            cout << _arr[i] << "|";
        cout << _arr;
        cout << endl;
    }
#endif // NDEBUG

private:
    size_t _num;
    unsigned int * _arr;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    size_t count;
    cin >> count;
    while(count--)
    {
        HashSet<n_tuple> my_set(500);
        size_t tuple_num;
        cin >> tuple_num;
        n_tuple my_tuple(tuple_num);
        for(size_t i = 0;i < tuple_num;++i)
        {
            unsigned int data;
            cin >> data;
            my_tuple.set(i, data);
        }
#ifndef NDEBUG
        my_tuple.print_data();
#endif // NDEBUG
        my_set.insert(my_tuple);
#ifndef NDEBUG
        my_set.print_all_in_hash();
#endif // NDEBUG
        while(true)
        {
            if(my_tuple.is_all_zero())
            {
                cout << "ZERO" << endl;
                break;
            }
            my_tuple.to_next_step();
            if(my_set.check(my_tuple))
            {
                cout << "LOOP" << endl;
                break;
            }
#ifndef NDEBUG
            my_tuple.print_data();
#endif // NDEBUG
            my_set.insert(my_tuple);
#ifndef NDEBUG
            my_set.print_all_in_hash();
#endif // NDEBUG
        }
    }

#ifndef NDEBUG
    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
#endif // NDEBUG
    return 0;
}

