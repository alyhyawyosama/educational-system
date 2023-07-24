#ifndef HELPER_H_
#define HELPER_H_

#include <algorithm>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::shared_ptr;



struct Helper {

    static int RunMenu(vector<string> &menu);
    static int ReadInt(int low, int high);

};

#endif /* HELPER_H_ */
