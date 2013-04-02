
#include <iostream>
#include <map>
using namespace std;

#include <stdlib.h>
#include "map.h"

template <class K, class V>
class Entry {

    private:
        K key;
        V value;

    public:
        Entry(K key, V value){
            this->key   = key;
            this->value = value;
        }

        K getkey(){
            return key;
        }

        V getValue(){
            return value;
        }
};

int main(int argc, char* argv[]){

    map<int, string> _mapping;

    _mapping.insert(pair<int, string>(500, "fabiojose"));

    pair<map<int, string>::iterator, bool> _returned = _mapping.insert(pair<int, string>(500, "maria"));
    if(!_returned.second){
        cout<<"Exists: "<<_returned.first->second<<endl;
    }
    _mapping.insert(pair<int, string>(600, "jose"));

    map<int, string>::iterator _value = _mapping.find(500);
    if(_value != _mapping.end()){
        cout<<_value->second<<endl;
    }

    Entry<int, string>* _entry = new Entry<int, string>(200, "Jose");

    cout<<_entry->getkey()<<endl;
    cout<<_entry->getValue()<<endl;
    delete _entry;

    return EXIT_SUCCESS;
}
