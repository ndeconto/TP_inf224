#ifndef MULTIMEDIAMAP
#define MULTIMEDIAMAP


#include <map>
#include "Movie.h"
#include "Picture.h"
#include "Video.h"
#include "group.h"


class MultimediaMap  {


private :
    std::map<std::string, Multimedia_ptr> objectTable;
    std::map<std::string, Group_ptr> groupTable;


    template <typename objectType>
    objectType addObject(objectType obj);

public :
    MultimediaMap(){
    }


    Picture_ptr createPicture(float latitude=0., float longitude=0.,
                              std::string name="",  std::string pathname="");

    Video_ptr createVideo(float duration=0., std::string name="",
                          std::string pathname = "");
	
    Movie_ptr createMovie(const int * duration_array=nullptr, unsigned int length=0,
                          std::string name="", std::string pathname="");
	
    Group_ptr createGroup(std::string name="");


    Multimedia_ptr search(std::string name) const;

    bool display(std::string name) const;

    void play(std::string name, std::ostream& stream) const;


};






#endif 		//MULTIMEDIAMAP
