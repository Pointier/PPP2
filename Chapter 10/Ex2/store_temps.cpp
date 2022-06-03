#include "temp.h";

default_random_engine& get_rand()
{
	static default_random_engine ran;
	return ran;
};

void seed_randint(int s) { get_rand().seed(s); }

inline int randint(int min, int max) { return uniform_int_distribution<>{min, max}(get_rand()); }

inline int randint(int max) { return randint(0, max); }



Reading rand_reading()
{
	Reading r;
	const int temp_max = 200;
	const int temp_min = -200;
	int h;
	h = randint(0, 24);
	double t{  };
	t = randint(temp_min, temp_max) + randint(0, 10) / double(10);

	char j;
	int k;
	k = rand()%2;
	if (k == 1) j = 'c';
	else j = 'f';

	r.hour = h;
	r.temp = t;
	r.t = j;
	return r;
}

ostream& operator<<(ostream& os, Reading r)
{
	return os << r.hour << ' ' << r.temp <<' ' << r.t;
}
	

void write_file(int n)
{
	
	string filename{ "raw_temp.txt" };
	ofstream ofs{ filename };
	ofs.exceptions(ofs.exceptions() | ios_base::badbit);
	if (!ofs) error ("can't open input file ", filename);

	for (int i{}; i < n; i++)
	{
		Reading temp;
		temp = rand_reading();
		ofs << temp;
		if (i + 1 != n) ofs << '\n';
	}

}
