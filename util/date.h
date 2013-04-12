#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>
#include <ctime>
using namespace std;

/**
 * One day in seconds.
 */
static const long ONE_DAY = 86400L;

/**
 * The Date.
 * fabiojose@gmail.com
 */
class Date {

    private:
        unsigned long date;

        int day, month, year;
        int hour, minute, second;

        struct tm* tinfo;

        struct tm* when(long theTime);
        void load(struct tm* now);

    public:
        Date();
        Date(long date);
        virtual ~Date();

        long getTime();
        bool after(Date* when);
        bool before(Date* when);
        bool equals(void* o);
        struct tm* getRaw();
        string toString();
};

#endif //DATE_H_INCLUDED
