using namespace std;

class bigNum
{
public:
	static const int MAX_DIGITS = 50;
	bigNum();
	bigNum(const char[]);
	bigNum(int);
	bigNum operator+(const bigNum&) const;
	bigNum operator+(int) const;
	bool operator<(const bigNum&) const;
	bool operator<(int) const;
	bool operator==(const bigNum&) const;
	bool operator==(int) const;
	bigNum operator-(const bigNum &) const ;
	bigNum operator-(int ) const ;
	friend bigNum operator -(int , const bigNum &);
	friend bigNum operator+(int, const bigNum&);
	friend bool operator<(int, const bigNum&);
	friend bool operator==(int, const bigNum&);
	friend ostream& operator<<(ostream&, const bigNum&);
	friend istream& operator>>(istream&, bigNum&);
private:
	int amtDigits;
	char number[MAX_DIGITS];
};