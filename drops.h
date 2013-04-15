#ifndef S_H_INCLUDED
#define S_H_INCLUDED

#ifdef _WIN32
  #define WINDOWS "WINDOWS"
#else
  #define LINUX "LINUX"
#endif

/**
 * Drops.
 * fabiojose@gmail.com
 */
class Drops {

    public:
        Drops(){

        }

        ~Drops(){

        }

        static char* runningOn(){
            //piece of code by OS
            #ifdef WINDOWS
              return WINDOWS;
            #else
              return LINUX;
            #endif
        }
};

#endif // S_H_INCLUDED
