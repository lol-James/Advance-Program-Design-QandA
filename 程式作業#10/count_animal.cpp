#include <bits/stdc++.h>

using namespace std;

struct Animal
{
    string name;
    int count;
};

struct Record
{
    string location;
    vector<Animal> animals;
};

int main()
{
    int n;
    vector<Record> records;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name, location;
        int count;
        cin >> name >> count >> location;

        bool found = false;
        for (auto &r : records) // traverse records
        {
            // The location has already existed in records.
            if (r.location == location)
            {
                bool animalFound = false;
                for (auto &a : r.animals) // traverse r.animals
                {
                    // The name has already existed in the location,
                    // so we directly increase the number of the corresponding animal.
                    if (a.name == name)
                    {
                        a.count += count;
                        animalFound = true;
                        break;
                    }
                }
                // The animal has not been found in the location,
                // so we put a new animal data in the location.
                if (!animalFound)
                    r.animals.push_back({name, count});
                found = true;
                break;
            }
        }
        // The location doesn't exist in records,
        // so we add a new location and put the animal data in.
        if (!found)
            records.push_back({location, {{name, count}}});
    }

    for (auto &r : records) // traverse records
    {
        cout << r.location << " : ";
        for (int i = 0; i < r.animals.size(); i++)
        {
            cout << r.animals[i].name << " " << r.animals[i].count;
            if (i < r.animals.size() - 1) // All non-last animals must be added ", " at the end.
                cout << ", ";
        }
        cout << endl;
    }

    return 0;
}
