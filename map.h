#ifndef MAP_H_INCLUDED
  #define MAP_H_INCLUDED
#endif

template <class K, class V>
class Map {

    public:
        Map(){

        }

        ~Map(){

        }

        virtual bool containsKey(K key) = 0;
};
