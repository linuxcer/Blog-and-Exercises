/*************************************************************************
 *  --------->    FILE: Map.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 08/30/2015    TIME:09:53:48
 ************************************************************************/
#include <map>
#include <iostream>
using namespace std;

int main() {
    map<string, int> maplist;
    // insert method 1
    maplist.insert({"Maths", 98});
    maplist.insert({"C", 94});

    // insert method 2
    maplist["C++"] = 100;
    maplist["Chinese"] = 90;

    // insert method 3
    maplist.insert(map<string, int> :: value_type("Date Structure", 91));

    // delete 
    map <string, int>::iterator it;
    it = maplist.find("C");
    if (it != maplist.end()) {
        maplist.erase(it);
        cout << "Find OK so delete it !" << endl;
    } else {
        cout << "Didn't Find so delete fail !" << endl;
    }

    // update
    maplist["C++"] = 99;

    // search
    it = maplist.find("C++");
    if (it != maplist.end()) {
        cout << "Find OK, " << it->first << ":" << it->second << endl;
    } else {
        cout << "Didn't find" << endl;
    }
    return 0;
}

