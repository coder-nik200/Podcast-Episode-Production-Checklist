#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_EPISODES = 30;
const int TASK_COUNT = 8;

class PodcastEpisode
{
private:
  int episodeId = 0;
  string title;
  string host;
  string guest;
  string recordingDate;
  int durationMinutes = 0;
  bool checklist[TASK_COUNT] = {};

  static int totalEpisodes;

public:
  // Set episode details
  void setDetails(int id, const string &episodeTitle,
                  const string &hostName,
                  const string &guestName,
                  const string &date,
                  int duration)
  {
    this->episodeId = id;
    title = episodeTitle;
    host = hostName;
    guest = guestName;
    recordingDate = date;
    durationMinutes = duration;

    for (int i = 0; i < TASK_COUNT; i++)
    {
      checklist[i] = false;
    }

    totalEpisodes++;
  }

  inline int getId() const
  {
    return episodeId;
  }

  inline string getTitle() const
  {
    return title;
  }

  static int getTotalEpisodes()
  {
    return totalEpisodes;
  }

  void showSummary() const
  {
    cout << "ID: " << episodeId
         << " | Title: " << title
         << " | Host: " << host << '\n';
  }

  void showDetails() const
  {
    cout << "\nEpisode ID: " << episodeId
         << "\nTitle: " << title
         << "\nHost: " << host
         << "\nGuest: " << guest
         << "\nRecording date: " << recordingDate
         << "\nDuration: " << durationMinutes << " minutes\n";
  }
};

int PodcastEpisode::totalEpisodes = 0;

int readInt(const string &prompt, int minimum, int maximum)
{
  int value;

  while (true)
  {
    cout << prompt;

    if (cin >> value && value >= minimum && value <= maximum)
    {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      return value;
    }

    cout << "Invalid number. Enter a value from "
         << minimum << " to " << maximum << ".\n";

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

string readText(const string &prompt)
{
  string value;

  while (true)
  {
    cout << prompt;
    getline(cin, value);

    if (value.find_first_not_of(" \t\r\n") != string::npos)
    {
      return value;
    }

    cout << "This field cannot be empty.\n";
  }
}

bool validDateFormat(const string &date)
{
  if (date.size() != 10 || date[4] != '-' || date[7] != '-')
  {
    return false;
  }

  for (int i = 0; i < 10; i++)
  {
    if (i == 4 || i == 7)
      continue;

    if (date[i] < '0' || date[i] > '9')
      return false;
  }

  int month = (date[5] - '0') * 10 + (date[6] - '0');
  int day = (date[8] - '0') * 10 + (date[9] - '0');

  return month >= 1 && month <= 12 &&
         day >= 1 && day <= 31;
}

string readDate()
{
  while (true)
  {
    string date = readText("Recording date (YYYY-MM-DD): ");

    if (validDateFormat(date))
    {
      return date;
    }

    cout << "Invalid date format or month/day range.\n";
  }
}

PodcastEpisode *findEpisode(PodcastEpisode episodes[], int count, int id)
{
  for (int i = 0; i < count; i++)
  {
    if (episodes[i].getId() == id)
    {
      return &episodes[i];
    }
  }

  return nullptr;
}

void addEpisode(PodcastEpisode episodes[], int &count)
{
  if (count >= MAX_EPISODES)
  {
    cout << "Storage full. Maximum "
         << MAX_EPISODES << " episodes.\n";
    return;
  }

  int id = readInt("Unique Episode ID (1-999999): ", 1, 999999);

  if (findEpisode(episodes, count, id) != nullptr)
  {
    cout << "Duplicate Episode ID. Nothing was added.\n";
    return;
  }

  string title = readText("Episode title: ");
  string host = readText("Host name: ");
  string guest = readText("Guest name (enter None if not applicable): ");

  string date = readDate();

  int duration = readInt("Duration in minutes (1-1440): ", 1, 1440);

  episodes[count].setDetails(
      id, title, host, guest, date, duration);

  count++;

  cout << "\nEpisode created successfully.\n";
}

void viewAll(const PodcastEpisode episodes[], int count)
{
  if (count == 0)
  {
    cout << "No episodes found.\n";
    return;
  }

  cout << "\nAll Episodes:\n";

  for (int i = 0; i < count; i++)
  {
    episodes[i].showSummary();
  }
}

int main()
{
  PodcastEpisode episodes[MAX_EPISODES];

  int count = 0;

  while (true)
  {
    cout << "\n===== PODCAST EPISODE PRODUCTION CHECKLIST =====\n";

    cout << "1. Add new episode\n";
    cout << "2. View all episodes\n";
    cout << "3. View total episodes\n";
    cout << "4. Exit\n";

    int choice = readInt("Choose (1-4): ", 1, 4);

    if (choice == 1)
    {
      addEpisode(episodes, count);
    }
    else if (choice == 2)
    {
      viewAll(episodes, count);
    }
    else if (choice == 3)
    {
      cout << "Total episodes: "
           << PodcastEpisode::getTotalEpisodes() << '\n';
    }
    else
    {
      cout << "Goodbye. Records are not saved after exit.\n";
      break;
    }
  }

  return 0;
}