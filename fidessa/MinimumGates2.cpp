/*
 * MinimumGates.cpp
 *
 *  Created on: May 6, 2016
 *      Author: gaohan
 */
/* At an airport you have a timetable for arrivals and departures.
 * You need to determine the minimum number of gates you*d need to provide so that all the planes can be placed at a gate as per their schedule.
 * The arrival and departure times for each plane are presented in two arrays, sorted by arrival time, and you're told the total number of flights for the
 * day. Assume that no planes remain overnight at the airport; all fly in and back out on the same day. Assume that if a plane departs in the same minute as another plane arrives, the arriving plane takes priority (i.e. you'll still need the gate for the departing plane). Write a function that returns
 * the minimum number of gates needed for the schedules you're given.
 * Example:
 * arrQ = {900, 940, 950, 1100,1500,1800}
 * depQ = {910,1200,1120, 1130,1900, 2000}
 * flights = 6
 */
#include <algorithm>
#include <queue>

using namespace std;
class MinimumGates {

public:
	int findMinGates(vector<int> arrQ, vector<int> depQ, int flight) {
		sort(arrQ.begin(), arrQ.end());
		sort(depQ.begin(), depQ.end());
		int count = 1;
		int deppointer = 0;
		for (int i = 1; i < flight; i++) {
			if (arrQ[i] >= depQ[deppointer]) {
				deppointer++;
			} else {
				count++;
			}
		}
		return count;
	}
};

