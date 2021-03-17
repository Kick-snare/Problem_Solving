#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //ifstream fin("station.inp"); ofstream fout("station.out");
    struct point
    {
        int x,y,z;
    };

    struct point station[4], vet[2];
    
    for(int i=0;i<4;i++) 
        cin >> station[i].x >> station[i].y >> station[i].z;
    for(int i=0;i<4;i+=2) {
        vet[i/2].x = station[i].x - station[i+1].x;
        vet[i/2].y = station[i].y - station[i+1].y;
        vet[i/2].z = station[i].z - station[i+1].z;
    }

    // for(int i=0;i<2;i++) cout << vet[i].x << ' ' << vet[i].y << ' ' << vet[i].z <<'\n';
    // for(int i=0;i<4;i++) cout << station[i].x << ' ' << station[i].y << ' ' << station[i].z <<'\n';
    


}

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

typedef struct {
    double x, y, z;
}Coord;

Coord a, b, c, d, target;
double minLen;

double getDistance(Coord &c1, Coord &c2) {
    return sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2) + pow(c2.z - c1.z, 2));
}
void init() {
    ifstream fileIn("station.inp");
    fileIn >> a.x >> a.y >> a.z; fileIn >> b.x >> b.y >> b.z;
    fileIn >> c.x >> c.y >> c.z; fileIn >> d.x >> d.y >> d.z;
    fileIn.close();
}
void divideAndConquer(Coord &head, Coord &tail) {
    Coord mid;
    mid.x = (head.x + tail.x) / 2;
    mid.y = (head.y + tail.y) / 2;
    mid.z = (head.z + tail.z) / 2;
    
    double headDistance = getDistance(head, target);
    double tailDistance = getDistance(tail, target);
    double midDistance = getDistance(mid, target);
    
    minLen = midDistance < minLen ? midDistance : minLen;
    minLen = headDistance < minLen ? headDistance : minLen;
    minLen = tailDistance < minLen ? tailDistance : minLen;
    
    if (abs(headDistance - tailDistance) < 1.0e-8) {
        target = mid;
        return ;
    }
    else {
        if (headDistance > tailDistance) {
            divideAndConquer(mid, tail);
        }
        else divideAndConquer(head, mid);
    }
}

int main(void) {
    init();
    target = c;
    minLen = getDistance(c, a);
    
    divideAndConquer(a, b);
    divideAndConquer(c, d);
    double tempLen = minLen;
    
    while (true) {
        divideAndConquer(a, b);
        if (abs(tempLen - minLen) < 1.0e-8) break;
        tempLen = minLen;
        divideAndConquer(c, d);
        if (abs(tempLen - minLen) < 1.0e-8) break;
        tempLen = minLen;
    }
    ofstream fileOut("station.out");
    if (minLen - ((double)int(minLen)) < 1.0e-8) {
        fileOut << int(minLen);
    }
    else {
        fileOut << int(minLen) + 1;
    }
    fileOut.close();
    return 0;
}

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

typedef struct {
    double x, y, z;
}Coord;

Coord a, b, c, d, target;
double minLen;

double getDistance(Coord &c1, Coord &c2) {
    return sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2) + pow(c2.z - c1.z, 2));
}
void init() {
    ifstream fileIn("station.inp");
    fileIn >> a.x >> a.y >> a.z; fileIn >> b.x >> b.y >> b.z;
    fileIn >> c.x >> c.y >> c.z; fileIn >> d.x >> d.y >> d.z;
    fileIn.close();
}
void divideAndConquer(Coord &head, Coord &tail) {
    Coord mid;
    mid.x = (head.x + tail.x) / 2;
    mid.y = (head.y + tail.y) / 2;
    mid.z = (head.z + tail.z) / 2;
    
    double headDistance = getDistance(head, target);
    double tailDistance = getDistance(tail, target);
    double midDistance = getDistance(mid, target);
    
    minLen = midDistance < minLen ? midDistance : minLen;
    minLen = headDistance < minLen ? headDistance : minLen;
    minLen = tailDistance < minLen ? tailDistance : minLen;
    
    if (abs(headDistance - tailDistance) < 1.0e-8) {
        target = mid;
        return ;
    }
    else {
        if (headDistance > tailDistance) {
            divideAndConquer(mid, tail);
        }
        else divideAndConquer(head, mid);
    }
}

int main(void) {
    init();
    target = c;
    minLen = getDistance(c, a);
    
    divideAndConquer(a, b);
    divideAndConquer(c, d);
    double tempLen = minLen;
    
    while (true) {
        divideAndConquer(a, b);
        if (abs(tempLen - minLen) < 1.0e-8) break;
        tempLen = minLen;
        divideAndConquer(c, d);
        if (abs(tempLen - minLen) < 1.0e-8) break;
        tempLen = minLen;
    }
    ofstream fileOut("station.out");
    if (minLen - ((double)int(minLen)) < 1.0e-8) {
        fileOut << int(minLen);
    }
    else {
        fileOut << int(minLen) + 1;
    }
    fileOut.close();
    return 0;
}
