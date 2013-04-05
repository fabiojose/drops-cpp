/**
 * The Strategy Design Pattern.
 * fabiojose@gmail.com
 */

#ifndef STRATEGY_H_INCLUDED
#define STRATEGY_H_INCLUDED

#include <set>
using namespace std;

#include "util.h"
#include "util/map.h"
#include "util/properties.h"

template<class T, class R>
class Strategy {

    public:
        Strategy(){

        }

        ~Strategy(){

        }

        virtual R execute(T t) = 0;
};

class PropertiesStrategy: public Strategy<string, Map<string, string>*> {

    private:
        Properties* properties;

    public:
        PropertiesStrategy(Properties* properties){
            this->properties = properties;
        }

        ~PropertiesStrategy(){

        }

        /**
        * Search keys based on baseKey and populate a Map.
        */
        Map<string, string>* execute(string baseKey){
            Map<string, string>* _result = new HashMap<string, string>();

            set<string> _keys = properties->keySet();
            for(set<string>::iterator _key = _keys.begin(); _key != _keys.end(); ++_key){

                if(UtilString::startsWith((string)*_key, baseKey)){
                    _result->put((string)*_key, properties->getProperty((string)*_key));
                }

            }

            return _result;
        }
};

#endif // STRATEGY_H_INCLUDED
