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



Video_ptr MultimediaMap::createVideo(float duration, std::__cxx11::string name,
                                     std::string pathname){

    return addObject(Video_ptr(new Video(duration, name, pathname)));

}


Movie_ptr MultimediaMap::createMovie(const int *duration_array, unsigned int length,
                                     std::string name, std::string pathname) {
    return addObject(Movie_ptr(new Movie(duration_array, length, name, pathname)));

}


Group_ptr MultimediaMap::createGroup(std::string name){

    Group_ptr g_ptr(new Group(name));
    if (groupTable.find(name) == groupTable.end())
        groupTable[name] = g_ptr;
    else {
        std::cerr << "[--]\tERROR : Impossible to create group with name = ";
        std::cerr << obj->getName() << "\n\tThis name is already in database" << std::endl;
        return Group_ptr(nullptr);
    }

    return g_ptr;
}
