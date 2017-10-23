#include "Movie.h"


template <class T>
T sum(const T* array, unsigned int size){
    T s = 0;
    for (unsigned int i = 0; i < size; i++) s += array[i];
    return s;
}


Movie::Movie(const int* array, unsigned int length,
             std::string name, std::string pathname) :
        Video(sum(array, length), name, pathname){

    duration_array = nullptr;
    setChapiterDuration(array, length);
}


Movie::Movie(const Movie& from) : Video(from){

    duration_array = nullptr;
    Movie::setChapiterDuration(from.getChapiterDuration(), from.getNumberOfChapiter());
}

Movie::~Movie() {
    delete[] duration_array;
}


Movie& Movie::operator=(const Movie& from){
    Video::operator=(from);

    setChapiterDuration(from.getChapiterDuration(), from.getNumberOfChapiter());

    return *this;

}

const int* Movie::getChapiterDuration() const {
    return (const int*) duration_array;
}

void Movie::setChapiterDuration(const int* array,  unsigned int length) {

    delete[] duration_array;

    this->duration_array = new int[length];
    std::copy(array, array + length, duration_array);
    Video::setDuration(sum<int>(array, length));

    array_length = length;
}

void Movie::display(std::ostream& stream) const{
    Video::display(stream);

    for (unsigned int i = 0; i < array_length; i++) {
        stream << duration_array[i] << " ";
    }
    stream << std::endl;
}


void Movie::setDuration(float duration) {
    std::cout << "[-] WARNING : You cannot specify the duration of a movie ! "
              << "It's the sum of the duration of each chapiter" << std::endl;
}
