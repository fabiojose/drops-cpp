#ifndef EXAMPLE_H_INCLUDED
#define EXAMPLE_H_INCLUDED

class Example {

    public:
        Example();
        virtual ~Example();

        //a pure virtual method
        virtual int execute(int, char*[]) = 0;

};

#endif // EXAMPLE_H_INCLUDED
