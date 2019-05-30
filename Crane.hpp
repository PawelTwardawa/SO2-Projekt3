//Klasa żuraw będzie zasobem, będzie blokowana.
//Posiada nr.

#include <atomic>
#include <mutex>

class Crane
{
public:
    int nr;
    int x;
    int y;
    std::atomic<bool> isUsed;
    std::mutex mutex;

    Crane(int N, int x, int y);
    void Do();
};