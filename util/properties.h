#ifndef PROPERTIES_H_INCLUDED
#define PROPERTIES_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "map.h"
#include "../util.h"

/**
 * Properties.
 * fabiojose@gmail.com
 *
 * A "key = value" file style.
 */
class Properties: public HashMap<string, string> {

    private:
        void process(string property);

    public:
        Properties();
        virtual ~Properties();

        void load(fstream &inStream);

        string getProperty(string key);
        string getProperty(string key, string defaultValue);

        string setProperty(string key, string value);
};

#endif //PROPERTIES_H_INCLUDED
