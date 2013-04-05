
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "util/date.h"

int main(int argc, char* argv[]){


    Date* _now = new Date();
    cout<<_now->toString()<<endl;

    Date* _tomorrow = new Date(_now->getTime() + UtilDate::ONE_DAY);
    cout<<_tomorrow->toString()<<endl;

    UtilDate* _util = new UtilDate();

    cout<<"Before: "<<_now->before(_tomorrow)<<endl;
    cout<<"After.: "<<_now->after(_tomorrow)<<endl;
    cout<<"Equals: "<<_now->equals(_tomorrow)<<endl;
    cout<<"Equals: "<<_now->equals(_now)<<endl;
    cout<<"Equals: "<<_now->equals(_util)<<endl;

    delete _now;
    delete _tomorrow;
    delete _util;

    return EXIT_SUCCESS;
}
