#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

class GeoPoint {
public:
	double lat;
	double lon;
	string title;

    GeoPoint()
	{
		this->lat = 0;
		this->lon = 0;
	}

	GeoPoint(double lat, double lon)
	{
		this->lat = lat;
		this->lon = lon;
	}

	void Step(GeoPoint step)
	{
		this->lat += step.lat;
		this->lon += step.lon;
	}

	void NewTitle(int j, int i, string alphabet)
	{
		ostringstream ostJ;
		ostJ << (j+1);
		if (i < (int)alphabet.length()) {
			title = alphabet[i] + ostJ.str();
		} else {
			ostringstream ostI;
			ostI << (i-alphabet.length()+1);
			title = ostI.str() + "-" + ostJ.str();
		}
	}

    void Clear()
	{
		this->lat = 0;
		this->lon = 0;
	}
};
