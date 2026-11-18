
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

struct DiskEpisode
{
  int id;
  char title[100];
  char host[50];
  char guest[50];
  float duration;
  char status;
};

class Episode
{
private:
  int id;
  string title;
  string host;
  string guest;
  float duration;
  char status;

  static int cnt;

public:
  Episode() : id(0), title(""), host(""), guest(""),
              duration(0), status('P')
  {
  }

  Episode(int x, string t = "Untitled",
          string h = "Not Assigned",
          string g = "Not Assigned",
          float d = 1.0, char s = 'P')
      : id(x), title(t), host(h), guest(g),
        duration(d), status(s)
  {
  }

  Episode(const Episode &e)
      : id(e.id), title(e.title), host(e.host),
        guest(e.guest), duration(e.duration),
        status(e.status)
  {
  }

  ~Episode()
  {
  }

  void setData(int &x)
  {
    string t, h, g;
    float d;
    char s;

    cout << "Enter Episode Title: ";
    getline(cin, t);

    while (t.empty())
    {
      cout << "Title cannot be empty. Enter again: ";
      getline(cin, t);
    }

    cout << "Enter Host Name: ";
    getline(cin, h);

    while (h.empty())
    {
      cout << "Host name cannot be empty. Enter again: ";
      getline(cin, h);
    }

    cout << "Enter Guest Name: ";
    getline(cin, g);

    while (g.empty())
    {
      cout << "Guest name cannot be empty. Enter again: ";
      getline(cin, g);
    }

    cout << "Enter Duration: ";
    cin >> d;

    while (cin.fail() || d <= 0)
    {
      cin.clear();
      cin.ignore(10000, '\n');

      cout << "Enter a valid duration: ";
      cin >> d;
    }

    cout << "Enter Status (P/C): ";
    cin >> s;

    while (s != 'P' && s != 'p' &&
           s != 'C' && s != 'c')
    {
      cout << "Enter P for Pending or C for Completed: ";
      cin >> s;
    }

    cin.ignore(10000, '\n');

    if (s == 'p')
      s = 'P';

    if (s == 'c')
      s = 'C';

    Episode temp(x, t, h, g, d, s);
    Episode copy(temp);

    *this = copy;
  }

  inline int getId()
  {
    return id;
  }

  static int getCount()
  {
    return cnt;
  }

  static void increaseCount()
  {
    cnt++;
  }

  void toFile(DiskEpisode &r)
  {
    r.id = id;

    strncpy(r.title, title.c_str(), 99);
    r.title[99] = '\0';

    strncpy(r.host, host.c_str(), 49);
    r.host[49] = '\0';

    strncpy(r.guest, guest.c_str(), 49);
    r.guest[49] = '\0';

    r.duration = duration;
    r.status = status;
  }

  friend void show(Episode &e);
};

int Episode::cnt = 0;

void show(Episode &e)
{
  cout << "\nEpisode ID: " << e.id;
  cout << "\nTitle: " << e.title;
  cout << "\nHost: " << e.host;
  cout << "\nGuest: " << e.guest;
  cout << "\nDuration: " << e.duration << " minutes";
  cout << "\nStatus: ";

  if (e.status == 'P')
    cout << "Pending";
  else
    cout << "Completed";

  cout << "\n-----------------------------\n";
}

int main()
{
  Episode arr[30];
  Episode *ptr = arr;

  int choice, x, flag, found;

  fstream file("episodes.dat", ios::in | ios::binary);

  if (file.is_open())
  {
    DiskEpisode r;

    while (file.read((char *)&r, sizeof(r)))
    {
      if (Episode::getCount() >= 30)
        break;

      Episode temp(r.id, string(r.title),
                   string(r.host), string(r.guest),
                   r.duration, r.status);

      Episode copy(temp);

      arr[Episode::getCount()] = copy;

      Episode::increaseCount();
    }

    file.close();
  }

  do
  {
    cout << "\n===== PRODCAST EPISODE PRODUCTION CHECKLIST =====\n";
    cout << "1. Add Episode\n";
    cout << "2. Display All Episodes\n";
    cout << "3. Search Episode\n";
    cout << "4. Update Episode\n";
    cout << "5. File Pointer Information\n";
    cout << "6. Exit\n";

    cout << "Enter your choice: ";

    if (!(cin >> choice))
    {
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "Invalid input. Enter a number.\n";
      continue;
    }

    switch (choice)
    {
    case 1:
    {
      if (Episode::getCount() >= 30)
      {
        cout << "Episode storage is full.\n";
        break;
      }

      cout << "Enter Episode ID: ";

      if (!(cin >> x))
      {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid ID.\n";
        break;
      }

      if (x <= 0)
      {
        cout << "ID must be positive.\n";
        break;
      }

      flag = 0;

      for (int i = 0; i < Episode::getCount(); i++)
      {
        if (ptr[i].getId() == x)
        {
          flag = 1;
          break;
        }
      }

      if (flag == 1)
      {
        cout << "Episode ID already exists.\n";
        break;
      }

      cin.ignore(10000, '\n');

      (ptr + Episode::getCount())->setData(x);

      DiskEpisode r;
      (ptr + Episode::getCount())->toFile(r);

      fstream file("episodes.dat",
                   ios::out | ios::binary | ios::app);

      if (file.is_open())
      {
        file.write((char *)&r, sizeof(r));

        if (file)
        {
          Episode::increaseCount();
          cout << "Episode added successfully.\n";
        }
        else
        {
          cout << "Error writing episode.\n";
        }

        file.close();
      }
      else
      {
        cout << "Unable to open file.\n";
      }

      break;
    }

    case 2:
    {
      if (Episode::getCount() == 0)
      {
        cout << "No episodes available.\n";
        break;
      }

      cout << "\n===== ALL EPISODES =====\n";

      for (int i = 0; i < Episode::getCount(); i++)
      {
        show(ptr[i]);
      }

      cout << "Total Episodes: "
           << Episode::getCount() << endl;

      break;
    }

    case 3:
    {
      cout << "Enter Episode ID to search: ";

      if (!(cin >> x))
      {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid ID.\n";
        break;
      }

      found = 0;

      fstream file("episodes.dat", ios::in | ios::binary);

      if (file.is_open())
      {
        DiskEpisode r;

        for (int i = 0; i < Episode::getCount(); i++)
        {
          file.seekg(i * sizeof(r), ios::beg);

          if (file.read((char *)&r, sizeof(r)))
          {
            if (r.id == x)
            {
              show(ptr[i]);
              found = 1;
              break;
            }
          }
        }

        file.close();
      }
      else
      {
        cout << "Unable to open file.\n";
        break;
      }

      if (found == 0)
        cout << "Episode not found.\n";

      break;
    }

    case 4:
    {
      cout << "Enter Episode ID to update: ";

      if (!(cin >> x))
      {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid ID.\n";
        break;
      }

      found = 0;

      fstream file("episodes.dat",
                   ios::in | ios::out | ios::binary);

      if (file.is_open())
      {
        DiskEpisode r;

        for (int i = 0; i < Episode::getCount(); i++)
        {
          file.seekg(i * sizeof(r), ios::beg);

          if (file.read((char *)&r, sizeof(r)))
          {
            if (r.id == x)
            {
              found = 1;

              cout << "\nEnter updated details:\n";

              (ptr + i)->setData(x);

              (ptr + i)->toFile(r);

              file.clear();

              file.seekp(i * sizeof(r), ios::beg);

              file.write((char *)&r, sizeof(r));

              if (file)
                cout << "Episode updated successfully.\n";
              else
                cout << "Error updating episode.\n";

              break;
            }
          }
        }

        file.close();
      }
      else
      {
        cout << "Unable to open file.\n";
        break;
      }

      if (found == 0)
        cout << "Episode not found.\n";

      break;
    }

    case 5:
    {
      fstream file("episodes.dat", ios::in | ios::binary);

      if (file.is_open())
      {
        cout << "Initial input pointer: "
             << file.tellg() << endl;

        file.seekg(0, ios::end);

        cout << "Total file size: "
             << file.tellg() << " bytes\n";

        file.seekg(0, ios::beg);

        cout << "Input pointer after seekg: "
             << file.tellg() << endl;

        file.close();
      }
      else
      {
        cout << "Unable to open file.\n";
      }

      break;
    }

    case 6:
    {
      cout << "Exiting program...\n";
      break;
    }

    default:
    {
      cout << "Invalid choice. Try again.\n";
    }
    }

  } while (choice != 6);

  return 0;
}
