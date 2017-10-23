#ifndef BASEMULTIMEDIABOX_H
#define BASEMULTIMEDIABOX_H


#include <string>
#include <iostream>
#include <ostream>

#include <memory>



class BaseMultimediaBox
{
private :
    std::string name;
    std::string pathname;

public:
    BaseMultimediaBox();
    BaseMultimediaBox(std::string name, std::string pathname);
    virtual ~BaseMultimediaBox();

    std::string getName() const;
    std::string getPathName() const;

    void setName(std::string new_name);
    void setPathName(std::string new_pathname);

    virtual void display(std::ostream& stream) const;

    virtual void play() const = 0;

};


typedef std::shared_ptr<BaseMultimediaBox> shared_Multimedia_ptr;
typedef std::unique_ptr<BaseMultimediaBox> unique_Multimedia_ptr;

typedef shared_Multimedia_ptr Multimedia_ptr;

#endif // BASEMULTIMEDIABOX_H
