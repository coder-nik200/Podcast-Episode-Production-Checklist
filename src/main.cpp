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

public:
  void showSummary() const
  {
    cout << "Podcast Episode Production Checklist\n";
  }

  void setDetails(int id, const string &episodeTitle, const string &hostName, const string &guestName, const string &date, int duration)
  {
    this->episodeId = id;
    title = episodeTitle;
    host = hostName;
    guest = guestName;
    recordingDate = date;
    durationMinutes = duration;

    for (int i = 0; i << TASK_COUNT; i++)
    {
      checklist[i] = false;
    }
  }

  inline int getId() const
  {
    return episodeId;
  }

  inline string getTitle() const
  {
    return title;
  }
};

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

    cout << "Invalid number. Enter a value from " << minimum << " to " << maximum << ".\n";

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

    if (value.find_first_not_of("\t\r\n") != string::npos)
      return value;

    cout << "This field cannot be empty.\n";
  }
}

bool validDateFormat(const string &date)
{
  if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    return false;

  for (int i = 0; i < 10; i++)
  {
    if (i == 4 || i == 7)
      continue;

    if (date[i] < '0' || date[i] > '9')
      return false;
  }

  int month = (date[5] - '0') * 10 + (date[6] - '0');
  int day = (date[8] - '0') * 10 + (date[9] - '0');

  return month >= 1 && month <= 12 && day >= 1 && day <= 31;
}

string readDate()
{
  while (true)
  {
    string date = readText("Recording date (YYYY-MM-DD): ");

    if (validDateFormat(date))
      return date;

    cout << "Invalid date format or month/day range.\n";
  }
}

int main()
{
    cout << "\n===== PODCAST EPISODE INPUT VALIDATION =====\n";

    int id = readInt("Enter Episode ID (1-999999): ", 1, 999999);

    string title = readText("Enter Episode Title: ");

    string host = readText("Enter Host Name: ");

    string guest = readText("Enter Guest Name: ");

    string date = readDate();

    int duration = readInt("Enter Duration (1-1440): ", 1, 1440);

    cout << "\n===== ENTERED EPISODE DETAILS =====\n";

    cout << "Episode ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Host: " << host << endl;
    cout << "Guest: " << guest << endl;
    cout << "Recording Date: " << date << endl;
    cout << "Duration: " << duration << " minutes" << endl;

    return 0;
}