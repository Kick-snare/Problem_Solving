#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

struct point { double x,y,z; };
struct point a,b,c,d, tmp;
double forward_len;

double get_len(struct point &A, struct point &B){ return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2)+pow(A.z-B.z,2)); }

void make_vertical(struct point &A, struct point &B){
    struct point H;

    H.x = (A.x+B.x)/2;
    H.y = (A.y+B.y)/2;
    H.z = (A.z+B.z)/2;

    double A2tmp,B2tmp,H2tmp;
    A2tmp = get_len(A, tmp);
    B2tmp = get_len(B, tmp);
    H2tmp = get_len(H, tmp);

    forward_len = max(A2tmp,forward_len);
    forward_len = max(B2tmp,forward_len);
    forward_len = max(H2tmp,forward_len);

    if (abs(A2tmp - B2tmp) < 1.0e-8) {
        tmp = H;
        return;
    }
    else
        if (A2tmp < B2tmp) get_len(A, H);
        else get_len(H, B);

}
int main(){
    ifstream fin("station.inp"); 
    ofstream fout("station.out");
    fin >> a.x >> a.y >> a.z >> b.x >> b.y >> b.z;
    fin >> c.x >> c.y >> c.z >> d.x >> d.y >> d.z;

    get_len(a, b);
    get_len(c, d);
    double tmp_len = forward_len;
    
    while(1){
        get_len(a, b);
        if (abs(tmp_len - forward_len) < 1.0e-8) break;
        tmp_len = forward_len;

        get_len(c, d);
        if (abs(tmp_len - forward_len) < 1.0e-8) break;
        tmp_len = forward_len;
    }
    if (forward_len - ((double)int(forward_len)) < 1.0e-8) fout << int(forward_len);
    else fout << int(forward_len) + 1;
    
    return 0;
}