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
};

int main()
{
  PodcastEpisode episode;
  episode.showSummary();

  return 0;
}