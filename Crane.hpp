//Klasa żuraw będzie zasobem, będzie blokowana.
//Posiada nr.

#include <atomic>
#include <mutex>

enum CraneStatus
{
    WaitingForShip,
    WitingForTruck,
    Working
};

class Crane
{
public:
    int nr;
    int x;
    int y;
    std::atomic<bool> isUsed;
    std::mutex mutex;
    std::atomic<bool> haveTruck;
    std::atomic<CraneStatus> status;

    Crane();
    Crane(int N, int x, int y);
    void Do();
};