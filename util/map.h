/**
 * Maps.
 * fabiojose@gmail.com
 */

#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <set>
#include <map>
#include <iostream>
using namespace std;

template <class K, class V>
class Map {

    public:
        Map(){

        }

        ~Map(){

        }

        /**
        * Pure virtual methods.
        */
        virtual bool containsKey(K key) = 0;
        virtual V get(K key) = 0;
        virtual V put(K key, V value) = 0;
        virtual V remove(K key) = 0;
        virtual int size() = 0;
        virtual void clear() = 0;
        virtual bool isEmpty() = 0;
        virtual set<K> keySet() = 0;

};

template <class K, class V>
class HashMap: public Map<K, V> {

    private:
        map<K, V> mapping;

    public:
        HashMap(){

        }

        ~HashMap(){

        }

        bool containsKey(K key){
            return mapping.find(key) != mapping.end();
        }

        V get(K key){
            V _result;

            typename map<K, V>::iterator _entry = mapping.find(key);
            if(_entry != mapping.end()){
                _result = _entry->second;
            }

            return _result;
        }

        V put(K key, V value) {
            V _result;

            if(!mapping.insert(pair<K, V>(key, value)).second){
                _result = mapping.find(key)->second;
                mapping.erase(key);

                //now, insert.
                mapping.insert(pair<K, V>(key, value));
            }

            return _result;
        }

        V remove(K key){
            V _result;

            typename map<K, V>::iterator _entry = mapping.find(key);
            if(_entry != mapping.end()){
                _result = _entry->second;

                //now, remove.
                mapping.erase(key);
            }

            return _result;
        }

        int size(){
            return mapping.size();
        }

        void clear(){
            mapping.clear();
        }

        bool isEmpty(){
            return mapping.empty();
        }

        set<K> keySet(){
            set<K> _result;

            typename map<K, V>::iterator _entry;
            for(_entry = mapping.begin(); _entry != mapping.end(); ++_entry){

                _result.insert(_entry->first);

            }

            return _result;
        }

        string toString(){
            string _result("");

            typename map<K, V>::iterator _entry;

            for(_entry = mapping.begin(); _entry != mapping.end(); ++_entry){
                _result.append(_entry->first).append(" = ").append(_entry->second);
                _result.append("\n");
            }

            return _result;
        }
};

#endif //MAP_H_INCLUDED
