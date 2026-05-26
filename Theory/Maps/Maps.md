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

``` for each loop 
for (auto element: map1) {
    key = element.first;
    value = element.second;
}