// A divide and conquer program to find convex
// hull of a given set of points.
#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;

// stores the centre of polygon (It is made
// global because it is used in compare function)
class point
{

public:
    int x, y;

    point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    bool operator<(const point &other)const
    {

        if (x != other.x)
        {
            return x < other.x;
        }

        return y < other.y;
    }
    ~point() {}
};
point mid(0, 0);

// determines the quadrant of a point
// (used in compare())
int quad(point p)
{
	if (p.x >= 0 && p.y >= 0)
		return 1;
	if (p.x <= 0 && p.y >= 0)
		return 2;
	if (p.x <= 0 && p.y <= 0)
		return 3;
	return 4;
}

// Checks whether the line is crossing the polygon
int orientation(point a, point b,
				point c)
{
	int res = (b.y-a.y)*(c.x-b.x) -
			(c.y-b.y)*(b.x-a.x);

	if (res == 0)
		return 0;
	if (res > 0)
		return 1;
	return -1;
}

// compare function for sorting
bool compare(point p1, point q1)
{
	point p = point(p1.x - mid.x,
								p1.y - mid.y);
	point q = point(q1.x - mid.x,
								q1.y - mid.y);

	int one = quad(p);
	int two = quad(q);

	if (one != two)
		return (one < two);
	return (p.y*q.x < q.y*p.x);
}

// Finds upper tangent of two polygons 'a' and 'b'
// represented as two vectors.
vector<point> merger(vector<point > a,
							vector<point > b)
{
	// n1 -> number of points in polygon a
	// n2 -> number of points in polygon b
	int n1 = a.size(), n2 = b.size();

	int ia = 0, ib = 0;
	for (int i=1; i<n1; i++)
		if (a[i].x > a[ia].x)
			ia = i;

	// ib -> leftmost point of b
	for (int i=1; i<n2; i++)
		if (b[i].x < b[ib].x)
			ib=i;

	// finding the upper tangent
	int inda = ia, indb = ib;
	bool done = 0;
	while (!done)
	{
		done = 1;
		while (orientation(b[indb], a[inda], a[(inda+1)%n1]) >=0)
			inda = (inda + 1) % n1;

		while (orientation(a[inda], b[indb], b[(n2+indb-1)%n2]) <=0)
		{
			indb = (n2+indb-1)%n2;
			done = 0;
		}
	}

	int uppera = inda, upperb = indb;
	inda = ia, indb=ib;
	done = 0;
	int g = 0;
	while (!done)//finding the lower tangent
	{
		done = 1;
		while (orientation(a[inda], b[indb], b[(indb+1)%n2])>=0)
			indb=(indb+1)%n2;

		while (orientation(b[indb], a[inda], a[(n1+inda-1)%n1])<=0)
		{
			inda=(n1+inda-1)%n1;
			done=0;
		}
	}

	int lowera = inda, lowerb = indb;
	vector<point> ret;

	//ret contains the convex hull after merging the two convex hulls
	//with the points sorted in anti-clockwise order
	int ind = uppera;
	ret.push_back(a[uppera]);
	while (ind != lowera)
	{
		ind = (ind+1)%n1;
		ret.push_back(a[ind]);
	}

	ind = lowerb;
	ret.push_back(b[lowerb]);
	while (ind != upperb)
	{
		ind = (ind+1)%n2;
		ret.push_back(b[ind]);
	}
	return ret;

}

// Brute force algorithm to find convex hull for a set
// of less than 6 points
vector<point> bruteHull(vector<point> a)
{
	// Take any pair of points from the set and check
	// whether it is the edge of the convex hull or not.
	// if all the remaining points are on the same side
	// of the line then the line is the edge of convex
	// hull otherwise not
	set<point >s;

	for (int i=0; i<a.size(); i++)
	{
		for (int j=i+1; j<a.size(); j++)
		{
			int x1 = a[i].x, x2 = a[j].x;
			int y1 = a[i].y, y2 = a[j].y;

			int a1 = y1-y2;
			int b1 = x2-x1;
			int c1 = x1*y2-y1*x2;
			int pos = 0, neg = 0;
			for (int k=0; k<a.size(); k++)
			{
				if (a1*a[k].x+b1*a[k].y+c1 <= 0)
					neg++;
				if (a1*a[k].x+b1*a[k].y+c1 >= 0)
					pos++;
			}
			if (pos == a.size() || neg == a.size())
			{
				s.insert(a[i]);
				s.insert(a[j]);
			}
		}
	}

	vector<point>ret;
	for (auto e:s)
		ret.push_back(e);

	// Sorting the points in the anti-clockwise order
	
	int n = ret.size();
	for (int i=0; i<n; i++)
	{
		mid.x += ret[i].x;
		mid.y += ret[i].y;
		ret[i].x *= n;
		ret[i].y *= n;
	}
	sort(ret.begin(), ret.end(), compare);
	for (int i=0; i<n; i++)
		ret[i] = point(ret[i].x/n, ret[i].y/n);

	return ret;
}

// Returns the convex hull for the given set of points
vector<point> divide(vector<point> a)
{
	// If the number of points is less than 6 then the
	// function uses the brute algorithm to find the
	// convex hull
	if (a.size() <= 5)
		return bruteHull(a);

	// left contains the left half points
	// right contains the right half points
	vector<point>left, right;
	for (int i=0; i<a.size()/2; i++)
		left.push_back(a[i]);
	for (int i=a.size()/2; i<a.size(); i++)
		right.push_back(a[i]);

	// convex hull for the left and right sets
	vector<point>left_hull = divide(left);
	vector<point>right_hull = divide(right);
	// cout << "left hull: " << endl;
    // for (point p : left_hull)
    // {
    //     cout << p.x << "," << p.y << endl;
    // }
    // cout << "right hull: " << endl;
    // for (point p : right_hull)
    // {
    //     cout << p.x << "," << p.y << endl;
    // }

	// merging the convex hulls
	return merger(left_hull, right_hull);
}

// Driver code
int main()
{
	freopen("in_dnc.txt", "r", stdin);
    freopen("out_dnc.txt", "w", stdout);

    int numOfTrees;
    cin >> numOfTrees;
    vector<point> a;

    for (int i = 0; i < numOfTrees; i++)
    {
        
        int tree_x, tree_y;
        cin >> tree_x >> tree_y;
        
        a.push_back(point(tree_x,tree_y));
    }

	int n = a.size();

	// sorting the set of points according
	// to the x-coordinate
	sort(a.begin(), a.end());
	vector<point >ans = divide(a);

	cout << "convex hull:\n";
	for (auto e:ans)
	cout << e.x << " "
			<< e.y << endl;

	return 0;
}


