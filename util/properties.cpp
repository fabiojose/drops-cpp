#include "properties.h"

//private
void Properties::process(string property){

    vector<string> _tokens = StringUtil::split(property, '=');
    if(_tokens.size() > 0){
        string _value("");
        string _key = _tokens.at(0);
        _key = StringUtil::trim(_key);

        //it's not a comment
        if('#'!= _key.at(0)){
            if(_tokens.size() == 2){
                _value = _tokens.at(1);
                _value = StringUtil::trim(_value);
            }

            put(_key, _value);
        }
    }
}

//public
Properties::Properties(){

}

Properties::~Properties(){

}

void Properties::load(fstream &inStream){

    string _property;
    while(getline(inStream, _property)){
        process(_property);
    }
}

string Properties::getProperty(string key){
    return get(key);
}

string Properties::getProperty(string key, string defaultValue){
    string _result = defaultValue;

    if(containsKey(key)){
        _result = get(key);
    }

    return _result;
}

string Properties::setProperty(string key, string value){

    return put(key, value)

}
