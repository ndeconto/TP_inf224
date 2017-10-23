#include "MultimediaMap.h"


template <typename objectPtr>
objectPtr MultimediaMap::addObject(objectPtr obj){

    if (objectTable.find(obj->getName()) == objectTable.end())
        objectTable[obj->getName()] = obj;
    else {
        std::cerr << "[--]\tERROR : Impossible to create object with name = ";
        std::cerr << obj->getName() << "\n\tThis name is already in database" << std::endl;
        return objectPtr(nullptr);
    }

    return obj;

}


Picture_ptr MultimediaMap::createPicture(float latitude, float longitude, std::string name,
                             std::string pathname) {

    return addObject(Picture_ptr(new Picture(latitude, longitude, name, pathname)));

}



Video_ptr MultimediaMap::createVideo(float duration, std::string name,
                                     std::string pathname){

    return addObject(Video_ptr(new Video(duration, name, pathname)));

}


Movie_ptr MultimediaMap::createMovie(const int *duration_array, unsigned int length,
                                     std::string name, std::string pathname) {
    return addObject(Movie_ptr(new Movie(duration_array, length, name, pathname)));

}


Group_ptr MultimediaMap::createGroup(std::string name){

    Group_ptr g_ptr(new Group<Multimedia_ptr>(name));
    if (groupTable.find(name) == groupTable.end())
        groupTable[name] = g_ptr;
    else {
        std::cerr << "[--]\tERROR : Impossible to create group with name = ";
        std::cerr << name << "\n\tThis name is already in database" << std::endl;
        return Group_ptr(nullptr);
    }

    return g_ptr;
}

Multimedia_ptr MultimediaMap::searchObject(std::string name) {

    if (objectTable.find(name) != objectTable.end()) {
        return objectTable[name];
    }
    else {
        std::cerr << "[--]\tERROR : no object named '" << name << "'\n";
        return nullptr;
    }
}

Group_ptr MultimediaMap::searchGroup(std::string name) {

    if (groupTable.find(name) != groupTable.end()) {
        return groupTable[name];
    }
    else {
        std::cerr << "[--]\tERROR : no group name '" << name << "'\n";
        return nullptr;
    }
}

bool MultimediaMap::display(std::string name, std::ostream& stream) const{

    if (objectTable.find(name) != objectTable.end()){
        objectTable.at(name)->display(stream);
        return true;
    }

    return false;
}

bool MultimediaMap::play(std::string name) const {
    if (objectTable.find(name) != objectTable.end()){
        objectTable.at(name)->play();
    }
    return false;
}
