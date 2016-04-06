#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct activity{
    int start, end;
};

bool sortMethod(activity * activity1, activity * activity2) {
    if (activity1->end == activity2->end) {
        return activity1->end < activity2->end;
    }
    return activity1->end < activity2->end;
}

int main() {
    int numberOfTestCases;
    vector<activity *> activityVector;

    cin >> numberOfTestCases;

    while (numberOfTestCases--) { // Perform each test case
        int numberOfActivities;
        int end = -1;
        int count = 0;
        cin >> numberOfActivities;

        while(numberOfActivities--) {
            activity * activity_p = new activity();
            cin >> activity_p->start;
            cin >> activity_p->end;

            activityVector.push_back(activity_p);
        }

        sort(activityVector.begin(), activityVector.end(), sortMethod);

        for (activity * currentActivity: activityVector) {
            if (currentActivity->start >= end) {
                count++;
                end = currentActivity->end;
            }
        }
        cout << count << endl;
        activityVector.clear();
    }
    return 0;
}
