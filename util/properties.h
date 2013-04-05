/**
 * Properties.
 * fabiojose@gmail.com
 *
 * A "key = value" file style.
 */
#ifndef PROPERTIES_H_INCLUDED
#define PROPERTIES_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "map.h"
#include "../util.h"

class Properties: public HashMap<string, string> {

    private:
        void process(string property){

            vector<string> _tokens = UtilString::split(property, '=');
            if(_tokens.size() > 0){
                string _value("");
                string _key = _tokens.at(0);
                _key = UtilString::trim(_key);

                //it's not a comment
                if('#'!= _key.at(0)){
                    if(_tokens.size() == 2){
                        _value = _tokens.at(1);
                        _value = UtilString::trim(_value);
                    }

                    put(_key, _value);
                }
            }
        }

    public:
        Properties(){

        }

        ~Properties(){

        }

        void load(fstream &inStream){

            string _property;
            while(getline(inStream, _property)){
                process(_property);
            }
        }

        string getProperty(string key){
            return get(key);
        }

        string getProperty(string key, string defaultValue){
            string _result = defaultValue;

            if(containsKey(key)){
                _result = get(key);
            }

            return _result;
        }

        string setProperty(string key, string value){

            return put(key, value);

        }

} ;

#endif //PROPERTIES_H_INCLUDED
