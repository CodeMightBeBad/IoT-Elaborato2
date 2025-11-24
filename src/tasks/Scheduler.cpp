#include <TimerOne.h>
#include "Scheduler.h"

volatile bool timerFlag;

/**
 * Timer interrupt handler
 */
void timerHandler() {
    timerFlag = true;
}

/**
 * Initializes the Scheduler object
 * @param basePeriod The base period of the scheduler in milliseconds
 */
void Scheduler::init(int basePeriod) {
    this->myBasePeriod = basePeriod;
    this->nTasks = 0;

    timerFlag = false;
    const long period = 1000l * basePeriod;

    Timer1.initialize(period);
    Timer1.attachInterrupt(timerHandler);
}

/**
 * Adds a task to the scheduler
 * @param task The task to add to the scheduler
 * @return wether the task has been successfully added or not
 */
bool Scheduler::addTask(Task *task) {
    if (nTasks < (MAX_TASKS - 1)) {
        taskList[nTasks] = task;
        nTasks++;
        return true;
    }

    return false;
}

/**
 * Schedules the tasks
 */
void Scheduler::schedule() {
    while (!timerFlag) {}
    timerFlag = false;

    for (int i = 0; i < nTasks; i++) {
        if (taskList[i]->update(myBasePeriod)) {
            taskList[i]->tick();
        }
    }
}
