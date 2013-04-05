#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <string>
#include <sstream>
#include <vector>
using namespace std;

class UtilString {

    public:
        UtilString(){

        }

        ~UtilString(){

        }

        static vector<string> split(string str, char delimiter){
            vector<string> _result;

            stringstream _sstream(str);
            string _token;

            while(getline(_sstream, _token, delimiter)){
                _result.push_back(_token);
            }

            return _result;
        }

        static string trim(string str, string delimiter){

            size_t _first = str.find_first_not_of(delimiter);
            if(string::npos != _first){
                str = str.substr( _first );
            }

            size_t _last = str.find_last_not_of(delimiter);
            if(string::npos != _last){
                str = str.substr(0, _last + 1);
            }

            return str;

        }

        static string trim(string str){
            return trim(str, " ");
        }

        static bool startsWith(string source, string prefix){
            bool _result = false;

            _result = (source.substr(0, prefix.size()) == prefix);

            return _result;
        }
};

#endif //UTIL_H_INCLUDED
