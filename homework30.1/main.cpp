#include <iostream>
#include <cpr/cpr.h>

using namespace std;

string request(const string &request);

int main() {
    system("chcp 65001");
    string req;
    cout << "Ваш запрос (get, post, put, delete, patch): ";
    getline(cin, req);
    while (req != "exit") {
        cout << request(req) << endl;
        cout << "Ваш запрос (get, post, put, delete, patch): ";
        getline(cin, req);
    }
    return 0;
}

string request(const string &req) {
    if (req == "get") {
        return cpr::Get(cpr::Url{"http://httpbin.org/get"}).text;
    } else if(req == "post") {
        return cpr::Post(cpr::Url{"http://httpbin.org/post"}).text;
    } else if(req == "put") {
        return cpr::Put(cpr::Url{"http://httpbin.org/put"}).text;
    } else if(req == "delete") {
        return cpr::Delete(cpr::Url{"http://httpbin.org/delete"}).text;
    } else if(req == "patch") {
        return cpr::Patch(cpr::Url{"http://httpbin.org/patch"}).text;
    } else {
        return "ВНИМАНИЕ: этот запрос не поддерживается!";
    }
}
