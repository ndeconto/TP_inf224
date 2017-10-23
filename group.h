#ifndef GROUP_H
#define GROUP_H

#include "BaseMultimediaBox.h"
#include <list>

#include <memory>

typedef std::list<BaseMultimediaBox*> MultimediaList;



/* make sure pointer_type is in set {BaseMultimediaBox*, smart_pointer} */
template <class pointer_type>
class Group : public std::list<pointer_type>{
private:
    std::string name;

public :
    Group(std::string name="") {this->name = name;}

    virtual ~Group() {}
    
    std::string getName() const {return this->name;}

    virtual void display(std::ostream& stream) const {
        for(typename std::list<pointer_type>::const_iterator ci = this->begin(); ci != this->end(); ci++)

            (*ci)->display(stream);
    }
};


typedef std::shared_ptr<Group<Multimedia_ptr>> Group_ptr;

#endif // GROUP_H
