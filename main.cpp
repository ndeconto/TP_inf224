//
//  main.cpp
//

#include <iostream>
#include <array>


#include "BaseMultimediaBox.h"
#include "Video.h"
#include "Picture.h"
#include "Movie.h"
#include "group.h"

#include "MultimediaMap.h"


int main(int argc, char* argv[]) {


    // the following lines don't work because of abstract methods added in part 4
    /*
    BaseMultimediaBox * b1 = new BaseMultimediaBox();
    BaseMultimediaBox * b2 = new BaseMultimediaBox("Toto", "this/is/a/path/to/a/file");

    b1->display(std::cout);
    b2->display(std::cout);
    */


    /** -----------------------       ARRAY TEST    ----------------------------**/
    std::cout << " \n\n\t\t *** ARRAY TEST *** \n\n";

    Video *v1 = new Video(0, "v1");
    Video *v2 = new Video(12, "v2");

    Picture *p1 = new Picture();
    Picture *p2 = new Picture(2, 5.7, "p2");

    std::array<BaseMultimediaBox*, 4> media_array = {v1, v2, p1, p2};

    for (unsigned int i = 0; i < media_array.size(); i++) {
        media_array[i]->display(std::cout);
    }





    /** -----------------------     COPY TEST    ------------------------------**/
    std::cout << " \n\n\t\t *** COPY *** \n\n";

    int duration[] = {1, 2, 3, 4};
    int duration2[] = {5, 7};
    int duration3[] = {8, 3, 45};
    Movie* m1 = new Movie((int *) duration, 4, "un film genial", "sur mon disque");
    m1->display(std::cout);

    Movie m2(*m1);
    m2.setDuration(12); //warns as it should

    Movie m3 = m2;

    m2.setChapiterDuration((int *) duration2, 2);
    m3.setChapiterDuration((int *) duration3, 3);

    //we make sure that m1, m2, and m3 and different
    //ie  that the copy was well done
    m1->display(std::cout);
    m2.display(std::cout);
    m3.display(std::cout);






    /** -----------------------       GROUPS    ------------------------------**/

    std::cout << " \n\n\t\t *** GROUPS *** \n\n";
    Group<BaseMultimediaBox*>* g = new Group<BaseMultimediaBox*>("foo");
    g->push_back(v1);
    g->push_back(p1);
    g->push_back(&m2);
    g->display(std::cout);




    /** -----------------------     SMART POINTERS ---------------------------**/

    std::cout << " \n\n\t\t *** SMART POINTERS *** \n\n";
    Video_ptr v1_ptr(v1);
    Picture_ptr p1_ptr(p1);
    Movie_ptr m1_ptr(m1);

    Group<shared_Multimedia_ptr>* g_smart = new Group<shared_Multimedia_ptr>("smart");

    g_smart->push_back(v1_ptr);
    g_smart->push_back(p1_ptr);
    g_smart->push_back(m1_ptr);
    g_smart->display(std::cout);


    /** --------------------------    MAPPING    ------------------------------**/
    std::cout << " \n\n\t\t *** MAPPING *** \n\n";

    MultimediaMap database;

    Picture_ptr data_p1 = database.createPicture(1, 2, "first Picture", ".");
    Picture_ptr data_p2 = database.createPicture(3, 4, "first Picture", "/");
    Picture_ptr data_p3 = database.createPicture();

    Video_ptr data_v1 = database.createVideo(5, "coucou", "home/");
    Movie_ptr data_m1 = database.createMovie((int *) duration, 3, "Harry Potter",
                                              "~/Movies/");

    database.searchObject("coucou")->display(std::cout);
    database.searchObject("Harry Potter")->display(std::cout);
    database.display("fkgj", std::cout);
    database.display("first Picture", std::cout);


    /** --------------------------    MAPPING    ------------------------------**/
    std::cout << " \n\n\t\t *** CLEANING *** \n\n";


    delete v2;
    delete p2;
    delete g;
    delete g_smart;

    /* other objects are automatically freed */
    /* we can use valgrind to check */



}
