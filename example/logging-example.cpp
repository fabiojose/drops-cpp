#include "logging-example.h"

LoggingExample::LoggingExample(){

}

LoggingExample::~LoggingExample(){

}

int LoggingExample::execute(int argc, char* argv[]){

    LoggerFactory _factory;
    _factory.setup();

    Logger* _logger = _factory.getLogger("ROOT");
    Logger* _ctl    = _factory.getLogger("CounterThread");

    _logger->trace("First logger publish!1");
    _logger->debug("First logger publish!2");
    _logger->info("First logger publish!3");
    _logger->warn("First logger publish!4");
    _logger->error("First logger publish!5");
    _logger->fatal("First logger publish!6");

    _logger->info("Massive logging...");
    for(int _i = 0; _i <= 10000; _i++){
        _logger->trace("Massive logging...");
    }

    _ctl->trace("Testing another logger....1");
    _ctl->debug("Testing another logger....2");
    _ctl->info("Testing another logger....3");
    _ctl->warn("Testing another logger....4");
    _ctl->error("Testing another logger....5");
    _ctl->fatal("Testing another logger....6");

    _ctl->info("Massive logging...");
    for(int _i = 0; _i <= 10000; _i++){
        _ctl->trace("Massive logging...");
    }

    return EXIT_SUCCESS;
}
