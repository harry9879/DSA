# Map in c++ STL

1. STL container which stores key-value pairs
2. The elements are stored in ascending/descending order.
3. Every key should be unique (No duplicate keys).
4. Implemented through BST.

## Header File Required

``` #include<map> ```

## Declaration 
``` map<key_datatype, value_datatype> map_name; ```

``` map<key_datatype, greater<datatype>> map_name; ```

## initialization 

```map<datatype1, datatype2> map_name = {{key1, value1},{key2, value2},}; ```

## insertion 

```cpp
    directory.insert(make_pair("ABC" , 379));
    directory[key] = value;
    directory["ABC"] = 379;
```

## printing the elements

```cpp for each loop 
for (auto element: map1) {
    key = element.first;
    value = element.second;
}
```

```cpp
// empty
m.erase(itr)
m.erase(index)
m.erase(start_index, end_index)

// size
m.size()

// max_size()
m.max_size()

// find
md.find(key)
// returns itr to element if present ,else it returns map.end() itr
// O(logn)

// count
count()
// no of occurence of key
// m.count(key)

upper_bound()
// returns an itr to next greater elements

lower_bound()
// returns itr to element if present else itr to next greater element,

begin() and end()
// itr to position after last element

rbegin() and rend()
// itr to first element in reverse order
```


# Unordered Map
1. STL container, store key-value pairs
2. elements are not ordered
3. keys will be unique

insertion, deletion, retrieval - O(1)


```cpp
// erase
m.erase(key);                  // erase by key
m.erase(itr);                  // erase by iterator
m.erase(begin_itr, end_itr);   // erase range

// find
m.find(key);
// returns iterator to element if found
// else returns m.end()

// count
m.count(key);
// returns 1 if key exists else 0

// iterators
m.begin();   // iterator to first element
m.end();     // iterator after last element

// reverse iterators
m.rbegin();  // reverse iterator to last element
m.rend();    // reverse iterator before first element
```

## Multimap

1. STL container store key-value pairs
2. elements are stored in an order- ascending/descending
3. duplicate key are allowed 
