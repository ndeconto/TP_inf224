#ifndef MOVIE_H
#define MOVIE_H

#include "Video.h"
#include <memory>

#include <iostream>

class Movie : public Video
{

private:
    int * duration_array;
    unsigned int array_length;

public:
    Movie(const int * duration_array=nullptr, unsigned int length=0,
          std::string name="", std::string pathname="");
    ~Movie();

    Movie(const Movie & from);
    Movie& operator=(const Movie & from);



    int getNumberOfChapiter() const {return array_length;}
    const int* getChapiterDuration() const;
    void setChapiterDuration(const int *, unsigned int);


    virtual void setDuration(float duration) override;
    virtual void display(std::ostream& stream) const override;
};


typedef std::shared_ptr<Movie> Movie_ptr;

#endif // MOVIE_H
