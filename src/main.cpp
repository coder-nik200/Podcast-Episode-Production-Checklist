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

int main()
{
  PodcastEpisode episode;
  episode.showSummary();

  return 0;
}