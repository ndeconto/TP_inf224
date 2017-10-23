#ifndef VIDEO_H
#define VIDEO_H

#include "BaseMultimediaBox.h"
#include <memory>

#include <stdlib.h>

class Video : public BaseMultimediaBox{

private:
    float duration;

public:
    Video(float duration=0., std::string name="", std::string pathname = "") :
        BaseMultimediaBox(name, pathname){
        this->duration = duration;
    }

    float getDuration() const { return duration;}
    virtual void setDuration(float duration) {this->duration = duration;}


    virtual void display(std::ostream& stream) const override {
            BaseMultimediaBox::display(stream);
            stream << "Video duration = " << duration << std::endl;
    }


    void play() const override {system(("mpv " + BaseMultimediaBox::getPathName()
                                        + " &").c_str());}


};


typedef std::shared_ptr<Video> Video_ptr;

#endif // VIDEO_H
