#ifndef STRATEGY_H_INCLUDED
  #define STRATEGY_H_INCLUDED
#endif

/**
 *
 * Strategy Design Pattern.
 *
 */
class Strategy {

    public:
        Strategy(){

        }

        ~Strategy(){

        }

        virtual void execute(void* argument) = 0;

};
