#ifndef OUTPUT_STREAM_H_INCLUDED
#define OUTPUT_STREAM_H_INCLUDED

class OutputStream {

    public:
        OutputStream();
        virtual ~OutputStream();

        //a pure virtual method
        virtual void write(char*, int) = 0;
};

#endif // OUTPUT_STREAM_H_INCLUDED
