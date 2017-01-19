#include <regex>
#include <cstdio>
#include <regex>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const regex EMAIL_FILTER("@gmail\\.com$");

struct Person {
    char name[21];
    char email[51];
};

bool filterFunction(Person* p);
bool compareFunction(Person* p1, Person* p2);

int main() {
    unsigned char N = 0;
    scanf("%hhu\n", &N);

    vector<Person*> people(N);
    for (unsigned char i = 0; i < N; i ++) {
        people[i] = new Person();
        scanf("%s %s", people[i]->name, people[i]->email);
    }

    vector<Person*> filteredPeople;
    for (Person* person : people) {
        if (filterFunction(person)) {
            filteredPeople.push_back(person);
        }
    }

    vector<Person*> sortedPeople(filteredPeople);
    sort(sortedPeople.begin(), sortedPeople.end(), compareFunction);

    for(const Person* person : sortedPeople) {
        printf("%s\n", person->name);
    }

    return 0;
}

bool filterFunction(Person* p) {
	bool match = regex_search(p->email,  EMAIL_FILTER);
    return match;
}

bool compareFunction(Person* p1, Person* p2) {
    return (strcmp(p1->name, p2->name) <= 0);
}
