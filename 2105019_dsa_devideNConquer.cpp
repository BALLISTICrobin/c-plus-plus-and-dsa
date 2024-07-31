#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

pair<int, int> mid;

int quad(pair<int, int> p)
{
    if (p.first >= 0 && p.second >= 0)
        return 1;
    if (p.first <= 0 && p.second >= 0)
        return 2;
    if (p.first <= 0 && p.second <= 0)
        return 3;
    return 4;
}

int orientation(pair<int, int> a, pair<int, int> b,pair<int, int> c)
{
    int res = (b.second - a.second) * (c.first - b.first) -(c.second - b.second) * (b.first - a.first);

    if (res == 0)
        return 0;
    if (res > 0)
        return 1;
    return -1;
}

bool compare(pair<int, int> p1, pair<int, int> q1)
{
    pair<int, int> p = make_pair(p1.first - mid.first,p1.second - mid.second);
    pair<int, int> q = make_pair(q1.first - mid.first,q1.second - mid.second);

    int one = quad(p);
    int two = quad(q);

    if (one != two)
        return (one < two);
    return (p.second * q.first < q.second * p.first);
}

vector<pair<int, int>> mergeHull(vector<pair<int, int>> a,vector<pair<int, int>> b)
{

    int leftSize = a.size(), rightSize = b.size();

    int rightMostIndexLH = 0, leftMostIndexRH = 0;
    for (int i = 1; i < leftSize; i++)
        if (a[i].first > a[rightMostIndexLH].first)
            rightMostIndexLH = i;

    for (int i = 1; i < rightSize; i++)
        if (b[i].first < b[leftMostIndexRH].first)
            leftMostIndexRH = i;
    //upper tangent
    int indexA = rightMostIndexLH, indexB = leftMostIndexRH;
    bool done = false;
    while (!done)
    {
        done = true;
        while (orientation(b[indexB], a[indexA], a[(indexA + 1) % leftSize]) >= 0)
            indexA = (indexA + 1) % leftSize;

        while (orientation(a[indexA], b[indexB], b[(rightSize + indexB - 1) % rightSize]) <= 0)
        {
            indexB = (rightSize + indexB - 1) % rightSize;
            done = false;
        }
    }

    int uppera = indexA, upperb = indexB;
    //lower tangent
    indexA = rightMostIndexLH, indexB = leftMostIndexRH;
    done = false;
   
    while (!done)
    {
        done = true;
        while (orientation(a[indexA], b[indexB], b[(indexB + 1) % rightSize]) >= 0)
            indexB = (indexB + 1) % rightSize;

        while (orientation(b[indexB], a[indexA], a[(leftSize + indexA - 1) % leftSize]) <= 0)
        {
            indexA = (leftSize + indexA - 1) % leftSize;
            done = false;
        }
    }

    int lowera = indexA, lowerb = indexB;
    vector<pair<int, int>> ret;

    int index = uppera;
    ret.push_back(a[uppera]);
    while (index != lowera)
    {
        index = (index + 1) % leftSize;
        ret.push_back(a[index]);
    }

    index = lowerb;
    ret.push_back(b[lowerb]);
    while (index != upperb)
    {
        index = (index + 1) % rightSize;
        ret.push_back(b[index]);
    }
    return ret;
}

vector<pair<int, int>> counterClockwise(vector<pair<int, int>> a)
{

    set<pair<int, int>> s;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            int x1 = a[i].first, x2 = a[j].first;
            int y1 = a[i].second, y2 = a[j].second;

            int a1 = y1 - y2;
            int b1 = x2 - x1;
            int c1 = x1 * y2 - y1 * x2;
            int pos = 0, neg = 0;
            for (int k = 0; k < a.size(); k++)
            {
                if (a1 * a[k].first + b1 * a[k].second + c1 <= 0)
                    neg++;
                if (a1 * a[k].first + b1 * a[k].second + c1 >= 0)
                    pos++;
            }
            if (pos == a.size() || neg == a.size())
            {
                s.insert(a[i]);
                s.insert(a[j]);
            }
        }
    }

    vector<pair<int, int>> ret;
    for (auto e : s)
        ret.push_back(e);

    mid = {0, 0};
    int n = ret.size();
    for (int i = 0; i < n; i++)
    {
        mid.first += ret[i].first;
        mid.second += ret[i].second;
        ret[i].first *= n;
        ret[i].second *= n;
    }
    sort(ret.begin(), ret.end(), compare);
    for (int i = 0; i < n; i++)
        ret[i] = make_pair(ret[i].first / n, ret[i].second / n);

    return ret;
}

vector<pair<int, int>> constructFence(vector<pair<int, int>> treeCoordinate)
{

    if (treeCoordinate.size() <= 5)
        return counterClockwise(treeCoordinate);

    vector<pair<int, int>> leftField, rightField;
    int i=0;
    while (i<treeCoordinate.size()/2)
    {
       leftField.push_back(treeCoordinate[i]);
         i++;
    }
     i = treeCoordinate.size() / 2;
        
   while( i < treeCoordinate.size())
      {
        rightField.push_back(treeCoordinate[i]);
        i++;
      }  

    vector<pair<int, int>> left_hull = constructFence(leftField);
    vector<pair<int, int>> right_hull = constructFence(rightField);
    

    return mergeHull(left_hull, right_hull);
}

int main()
{
    freopen("in_dnc.txt", "r", stdin);
    freopen("out_dnc.txt", "w", stdout);

    int numOfTrees;
    cin >> numOfTrees;
    vector<pair<int, int>> treeCoordinates;

    for (int i = 0; i < numOfTrees; i++)
    {

        int tree_x, tree_y;
        cin >> tree_x >> tree_y;

        treeCoordinates.push_back({tree_x, tree_y});
    }

    int n = treeCoordinates.size();

    sort(treeCoordinates.begin(), treeCoordinates.end());
    vector<pair<int, int>> ans = constructFence(treeCoordinates);

    cout << "convex polygonal fence's vertices:"<<endl;
    for (auto e : ans)
        cout << e.first << " "<< e.second << endl;

    return 0;
}
