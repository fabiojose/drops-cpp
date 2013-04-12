
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "util/date.h"

int main(int argc, char* argv[]){

    Date* _now = new Date();
    cout<<_now->toString()<<endl;

    Date* _tomorrow = new Date(_now->getTime() + ONE_DAY);
    cout<<_tomorrow->toString()<<endl;

    cout<<"Before: "<<_now->before(_tomorrow)<<endl;
    cout<<"After.: "<<_now->after(_tomorrow)<<endl;
    cout<<"Equals: "<<_now->equals(_tomorrow)<<endl;
    cout<<"Equals: "<<_now->equals(_now)<<endl;

    delete _now;
    delete _tomorrow;

    return EXIT_SUCCESS;
}
