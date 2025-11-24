#ifndef IOT_ELABORATO2_TASK_H
#define IOT_ELABORATO2_TASK_H

class Task {
    int taskPeriod = 0;
    int timeElapsed = 0;

public:
    virtual ~Task() = default;

    virtual void init(const int period) {
        taskPeriod = period;
        timeElapsed = 0;
    }

    virtual void tick() = 0;

    bool update(const int basePeriod) {
        timeElapsed += basePeriod;

        if (timeElapsed >= taskPeriod) {
            timeElapsed = 0;
            return true;
        }

        return false;
    }
};

#endif