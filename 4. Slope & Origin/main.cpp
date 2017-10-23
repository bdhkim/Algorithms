// Eduardo Portet
// Dong Hyung Kim

// HW 4 EC330
 

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {

	string filename = "points.txt";
	int N = 0;
	float x_val = 0;
	float y_val = 0;
	int count = 0;
	float m = 0;
	float b = 0;

	ifstream inputfile(filename.c_str());

	inputfile >> N;

	struct Point {
		float x, y;
		float slope;
		float intercept;
	} all_points[N];

	while (inputfile >> x_val >> y_val) {
		all_points[count].x = x_val;
		all_points[count].y = y_val;
		count++;
	}
	// Close the file
	inputfile.close();



	// START ALGORITHM //

	Point origin = all_points[0];
	origin.slope = 0;
	origin.intercept = 0;
	count = 0;
	Point temp[N];
	Point lines[N];
	int l = 0;
	bool no_rlines = true;

	while (count < N-3) {
		for (int i = count+1; i < N; ++i)
		{
			all_points[i].slope = ((all_points[i].y - origin.y)/(all_points[i].x - origin.x));
			all_points[i].intercept = (all_points[i].y - (all_points[i].x * all_points[i].slope));
		}
		temp[0] = origin;

		//cout << "ORIGIN IS: " << origin.x << " " << origin.y << endl;

		for (int i = count+1; i < N; ++i)
		{	
			temp[1] = all_points[i];
			int k = 2;

			//cout << "(" << all_points[i].x << "," << all_points[i].y << ")" << "m:" << all_points[i].slope << " b:" << all_points[i].intercept << endl;

			for (int j = i+1; j < N; ++j)
			{
				//cout << "(" << all_points[j].x << "," << all_points[j].y << ")" << "m:" << all_points[j].slope << " b:" << all_points[j].intercept << endl;
				if (all_points[j].slope == all_points[i].slope && all_points[j].intercept == all_points[i].intercept)
				{
					temp[k] = all_points[j];
					k++;
				}
			}
			//cout <<  "HERE" << endl << endl;
			for (int j = 0; j < l; ++j)
			{
				if (lines[j].slope == temp[1].slope && lines[j].intercept == temp[1].intercept)
				{
					no_rlines = false;
					break;
				}
				no_rlines = true;
			}

			if (k >= 4 && no_rlines)
			{
				//cout << "GROUP" << endl;
				lines[l] = temp[1];
				l++; 
				for (int j = 0; j < k; ++j)
				{
					cout << "(" << temp[j].x << "," << temp[j].y << ")" << endl;
				}
				cout << endl;
				break;
			}
		}
		count++;
		origin = all_points[count];
	}

	return 0;
}