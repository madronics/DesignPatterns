#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Journal
{
    string title;
    vector<string> entries;

    Journal(const string &title):title(title) {}

    void addEntry(const string &entry)
    {
        static int count = 1;
        entries.push_back(std::to_string(count++) + ": " + entry);
    }

    void save(const string& filename) // Bad Programming
    {
        ofstream ofs(filename);
        for (auto& e: entries)
        {
            ofs << e << endl;
        }
    }
};

struct PersistenceManager // Dosyaya yazmak dışında, database eklenebilirdi.
{
    static void save(Journal& j, const string& filename) // Good Programming
    {
        ofstream ofs(filename);
        for (auto& e: j.entries)
        {
            ofs << e << endl;
        }
    }
};

int main()
{
    Journal journal {"Dear Diary"};
    journal.addEntry("I ate a bug");
    journal.addEntry("I cried today");

    //journal.save("diary.txt"); // Bad Programming

    PersistenceManager pm;
    pm.save(journal, "diary.txt");
    return 0;
}
