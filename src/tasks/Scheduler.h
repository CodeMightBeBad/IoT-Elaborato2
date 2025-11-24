#ifndef IOT_ELABORATO2_SCHEDULER
#define IOT_ELABORATO2_SCHEDULER

#include "Task.h"
#define MAX_TASKS 50

class Scheduler {

    int myBasePeriod = 0;
    int nTasks = 0;
    Task* taskList[MAX_TASKS] = {};

public:
    virtual ~Scheduler() = default;

    void init(int basePeriod);
    virtual bool addTask(Task* task);
    virtual void schedule();
};

#endif