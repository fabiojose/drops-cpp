#include "properties-example.h"

PropertiesExample::PropertiesExample(){

}

PropertiesExample::~PropertiesExample(){

}

int PropertiesExample::execute(int argc, char* argv[]){

    fstream _input("log4cpp.properties");
    Properties* _properties = new Properties();

    _properties->load(_input);

    string _key1("formatter.FORMATTER.pattern");
    cout<<_key1<<" = "<<_properties->get(_key1)<<endl;

    string _key2("handler.FILE.file.name");
    cout<<_key2<<" = "<<_properties->get(_key2)<<endl;

    cout<<endl<<"Print all properties:"<<endl;
    cout<<_properties->toString();

    delete _properties;

    _input.close();

    return EXIT_SUCCESS;
}
