// Specification file for the College class
// Written By: A. Student
// Changed By: Shun Furuya
// IDE: Xcode

#ifndef COLLEGE_H
#define COLLEGE_H

//#include<iostream>
#include<string>
//#include<cstdlib>

// using namespace std;
    //^^^^^ This statement
    // in a header file of a complex project could create
    // namespace management problems for the entire project
    // (such as name collisions).
    // Do not write using namespace at the top level in a header file!

using std::string;

class College
{
    private:
        string code;
        string name;
        int rank;
        int cost;

    public:
        //constructors
        College();
        College(int, string, string, int);

        //setters
        void setCode(string cd){ code = cd;}
        void setName(string nm){ name = nm;}
        void setRank(int rk){ rank = rk;}
        void setCost(int cs){ cost = cs;}

        //getters
        string getCode() const {return code;}
        string getName() const {return name;}
        int getRank() const {return rank;}
        int getCost() const {return cost;}

        //other functions
        void hDdisplay()const;
        void vDisplay()const;
};

#endif
