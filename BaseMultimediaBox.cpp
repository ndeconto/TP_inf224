#include "BaseMultimediaBox.h"

BaseMultimediaBox::BaseMultimediaBox()
{
}

BaseMultimediaBox::BaseMultimediaBox(std::string name, std::string pathname){
    this->name = name;
    this->pathname = pathname;
}

#include <iostream>
BaseMultimediaBox::~BaseMultimediaBox(){
	std::cout << name << " : destruction \n";
}

std::string BaseMultimediaBox::getName()  const{
    return name;
}

std::string BaseMultimediaBox::getPathName()  const{
    return pathname;
}


void BaseMultimediaBox::setName(std::string new_name){
    name = new_name;
}

void BaseMultimediaBox::setPathName(std::string new_pathname){
    pathname = new_pathname;
}


void BaseMultimediaBox::display(std::ostream& stream) const{

    stream << "[.] BaseMultimediaBox " << name << "\t pathname = " << pathname << "\n";
}
