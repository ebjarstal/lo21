#include "iterator.h"

void test1() {
    Person me("Eric", "Bjarstal", 21);
    Person you("Vanessa", "Paradis", 28);
    cout << me << endl;
    cout << you << endl;
}

void test2() {
    vector<Person> liste = {
            Person ("Tom", "Poulain", 23),
            Person ("Agathe", "Vasseur", 21),
            Person ("Selenne", "Cao", 21)
    };
    Group amis(liste);
    PersonIterator it = amis.first();
    while (!it.isDone()) {
        cout << it.current() << endl;
        it.next();
    }
}

int main() {
    // test1();
    test2();
    return 0;
}