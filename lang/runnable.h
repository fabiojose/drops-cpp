#ifndef RUNNABLE_H_INCLUDED
#define RUNNABLE_H_INCLUDED

/**
 * The Runnable to use as a target of Thread.
 * fabiojose@gmail.com
 */
class Runnable{

    public:
        Runnable();
        virtual ~Runnable();

        virtual void run() = 0;
};

#endif // RUNNABLE_H_INCLUDED
