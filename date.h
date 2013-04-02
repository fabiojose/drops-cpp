/**
 *
 * The Date.
 * fabiojose@gmail.com
 */

#ifndef DATE_H_INCLUDED
  #define DATE_H_INCLUDED
#endif

#include <ctime>
using namespace std;

#include <stdio.h>

class Date {

    private:
        unsigned long date;

        int day, month, year;
        int hour, minute, second;

        struct tm* when(long theTime){
            time_t _time;
            if(0== theTime){
                _time = time(0);
            } else {
                _time = theTime;
            }

            date = _time;

            return localtime(&_time);
        }

        void load(struct tm* now){

            day    = now->tm_mday;
            month  = now->tm_mon  + 1;
            year   = now->tm_year + 1900;
            hour   = now->tm_hour;
            minute = now->tm_min;
            second = now->tm_sec;
        }

    public:
        Date(){
            struct tm* _now = when(0);

            load(_now);

            delete _now;
        }

        Date(long date){
            struct tm* _now = when(date);

            load(_now);

            delete _now;
        }

        ~Date(){

        }

        long getTime(){
            return date;
        }

        bool after(Date* when){
            return date > when->date;
        }

        bool before(Date* when){
            return date < when->date;
        }

        bool equals(void* o){
            bool _result = false;

            Date* _date = static_cast<Date*>(o);
            if(_date){
                _result = (date == _date->date);
            }

            return _result;
        }

        string toString(){
            string _result = "";

            char _buffer[256];
            sprintf(_buffer, "%02d/%02d/%02d %02d:%02d:%02d", day, month, year, hour, minute, second);

            _result = _buffer;
            return _result;
        }

};

class UtilDate {

    public:
        UtilDate(){

        }

        ~UtilDate(){

        }

        /**
         * One day in seconds.
         */
        static const long ONE_DAY = 86400L;

};
