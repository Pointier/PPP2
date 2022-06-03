#include "temp.h";

/*istream& operator>>(istream& is, Reading& r)
{
	int i;
	double t;
	char c;
	is >> i >> t >> c;
	r.hour = i;
	r.temp = t;
	r.t = c;


	return is ;
}
*/
vector<Reading> read_file()
{
	
	string filename{ "raw_temp.txt" };
	ifstream ifs{ filename };
	ifs.exceptions(ifs.exceptions() | ios_base::badbit);
	if (!ifs) error("can't open input file ", filename);

	vector<Reading> r;
	   	 
	Reading e{};
	while (true)
	{
		
		if (!(ifs >> e.hour >> e.temp >> e.t)) break;
		ifs >> e.hour >> e.temp >> e.t;
		if (e.t == 'c') e.temp = e.temp * 9 / 5 + 32;
		r.push_back(e);	
	}
	
	return r;
}

void mean(const vector<Reading>& r)
{
	double sum{};
	double mean{};
	for (int i{}; i < r.size(); i++)
	{
		sum += r[i].temp;
	}
	mean = sum / r.size();
	cout << "Mean is : " << mean << endl;

}

void median(const vector<Reading>& r)
{
	bool pair{ false };
	if (r.size() % 2 == 0) pair = true;

	vector<double> t;
	for (int i{}; i < r.size(); i++) {
		t.push_back(r[i].temp);
	}
	sort(t.begin(), t.end());

	for (int i{};i< t.size();i++)
		cout << t[i] << endl;

	double median{};
	int middle{};
	middle = t.size() / 2;
	cout << "middle is : " << middle << endl;
	if (pair)
		median = (t[middle-1] + t[(middle)]) / 2;
	else
		median = t[middle];

	cout << "Median is : " << median;
	
}
