#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

/**
 * TRACE < DEBUG < INFO < WARN < ERROR < FATAL
 */
enum Level {

    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL

};

const Level LOG4CPP_DEFAULT_LEVEL = WARN;

#endif // LEVEL_H_INCLUDED
