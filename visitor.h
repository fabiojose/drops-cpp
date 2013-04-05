/**
 * The Visitor Design Pattern.
 * fabiojose@gmail.com
 */
#ifndef VISITOR_H_INCLUDED
#define VISITOR_H_INCLUDED

template<class T, class R>
class Visitor {

    public:
        Visitor(){

        }

        ~Visitor(){

        }

        virtual R visit(T t) = 0;
};

#endif // VISITOR_H_INCLUDED
