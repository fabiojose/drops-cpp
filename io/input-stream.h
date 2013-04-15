#ifndef INPUT_STREAM_H_INCLUDED
#define INPUT_STREAM_H_INCLUDED

class InputStream {

    public:
        InputStream();
        virtual ~InputStream();

        //a pure virtual method
        virtual int read(char*, int) = 0;
};

#endif // INPUT_STREAM_H_INCLUDED
