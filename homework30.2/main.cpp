#include <iostream>
#include <cpr/cpr.h>

using namespace std;

string getHeader(string &str);

int main() {
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
                               cpr::Header{{"accept", "text/html"}});
    cout << getHeader(r.text) << endl;
    return 0;
}

string getHeader(string &str) {
    int begin = 0;
    int end = 0;
    if (str.find("<h1>") != string::npos) {
        begin = str.find("<h1>") + 4;
    } else if (str.find("<H1>") != string::npos) {
        begin = str.find("<H1>") + 4;
    }
    if (str.find("</h1>") != string::npos) {
        end = str.find("</h1>") - begin;
    } else if (str.find("</H1>") != string::npos) {
        end = str.find("</H1>") - begin;
    }
    return str.substr(begin, end);
}
