#ifndef PICTURE_H
#define PICTURE_H

#include <ostream>
#include <memory>
#include "BaseMultimediaBox.h"

class Picture : public BaseMultimediaBox{

private:

    float latitude;
    float longitude;

public:

    Picture(float latitude=0., float longitude=0., std::string name="",
            std::string pathname="") : BaseMultimediaBox(name, pathname) {
        this->latitude = latitude;
        this->longitude = longitude;
    }


    void setLatitude(float new_latitude) {latitude = new_latitude;}
    float getLatitude() const {return latitude;}

    float getLongitude() const {return longitude;}
    void setLongitude(float new_longitude) {longitude = new_longitude;}


    virtual void display(std::ostream& stream) const override {
        BaseMultimediaBox::display(stream);
        stream << "Picture (lat, long) = (" << latitude << ", " << longitude  << ")\n";
    }



    void play() const override {system(("imagej " + BaseMultimediaBox::getPathName()
                                        + " &").c_str());}

};

typedef std::shared_ptr<Picture> Picture_ptr;

#endif // PICTURE_H
