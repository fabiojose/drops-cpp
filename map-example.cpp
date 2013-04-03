
#include <iostream>
#include <map>
using namespace std;

#include <stdlib.h>
#include "map.h"

int main(int argc, char* argv[]){

    Map<int, string>* _hmap = new HashMap<int, string>();

    cout<<_hmap->put(500, "fabiojose")<<endl;

    cout<<"Updating key 500: "<<_hmap->put(500, "maria")<<endl;
    cout<<_hmap->put(600, "jose")<<endl;

    cout<<"size: "<<_hmap->size()<<endl;
    cout<<"contains key 600: "<<_hmap->containsKey(600)<<endl;
    cout<<"contains key 500: "<<_hmap->containsKey(500)<<endl;

    cout<<"getting key 500.: "<<_hmap->get(500)<<endl;
    cout<<"removing key 500: "<<_hmap->remove(500)<<endl;
    cout<<"getting key 500.: "<<_hmap->get(500)<<endl;
    cout<<"contains key 500: "<<_hmap->containsKey(500)<<endl;

    cout<<"size: "<<_hmap->size()<<endl;
    cout<<"cleaning the map."<<endl;
    _hmap->clear();
    cout<<"size: "<<_hmap->size()<<endl;

    delete _hmap;

    return EXIT_SUCCESS;
}

